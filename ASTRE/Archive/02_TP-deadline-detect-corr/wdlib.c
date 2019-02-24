#include "wdlib.h"
#include "types.h"

void wd_threadbody();
extern struct timespec start_timespec;


int WD_ALARM=-1; 
sigset_t WD_sigset;
pthread_t WD_thread_Id; 

int global_init_wd()
{
  struct sched_param param;
  pthread_attr_t     attr;
  int sys_ret;
  
  // First initialize ssynchronisation between task and WD thread to
  // avoid crashes
  sigemptyset(&WD_sigset);
  sigaddset (&WD_sigset, SIGRTMIN);
  WD_ALARM=SIGRTMIN;
  sigprocmask (SIG_BLOCK, &WD_sigset, NULL);
  
  // then init and start WD thread 
  sys_ret = pthread_attr_init (&attr);
  if (sys_ret != 0)
  {
#ifdef DEBUG
    printf("Error: fail to init WD thread attr %d\n", sys_ret);
#endif
    return sys_ret;
  }
  sys_ret=0;
  sys_ret+=pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
  sys_ret+=pthread_attr_setscope (&attr, PTHREAD_SCOPE_SYSTEM);
  sys_ret+=pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
  param.sched_priority=sched_get_priority_max(SCHED_FIFO); 
  sys_ret+=pthread_attr_setschedparam (&attr, &param); 
  if (sys_ret!=0)
  {
    printf("error in WD thread init\n"); 
    return sys_ret;
  }
  
  sys_ret = pthread_create (&WD_thread_Id, 
			    &attr, 
			    (void* (*)(void*))&wd_threadbody, 
			    NULL);
   return E_OK; 
}

void wd_recovery()
{
  printf("TODO recovery\n");
}

void  wd_threadbody()
{
  int count=0;
  while(count<1000)
  {
    // variable used to store the id of the signal that wake up sigwait. 
    siginfo_t caught ; 
    // implementation alternative sigwaitinfgo 
    sigwaitinfo(&WD_sigset, &caught);
    printf("##############  faulty thread = %d\n####################\n", 
	   caught.si_timerid );
    wd_recovery(); 	 
  }
  return;
}

int local_init_wd(wd_desc_t * wd, periodic_thread_config_t * td)
{
  struct sigevent sigev;
  int ret ;
  static int wd_num; 
  if (wd==0) {printf("error wd init");}
  wd->wd_alrm=WD_ALARM;
  wd->task_descriptor=td;
  sigev.sigev_notify = SIGEV_SIGNAL;
  sigev.sigev_signo = wd->wd_alrm;
  sigev.sigev_value.sival_ptr = &(wd->timer_id);
  ret= timer_create (CLOCK_MONOTONIC, &sigev, &(wd->timer_id));
  return ret ;
}

int set_wd( wd_desc_t * wd)
{
  // duration represent the amount of milliseconds before wd exprire
  // 1) transform duration into absolute time agaisnt wd timer
  struct itimerspec* timerDef; 
  timerDef= &wd->tDef;
 
  // define itimerspec :
  // recall that it contains two timespec structs  
  // itinterval should be Zero (e.g. both subfield equal to 0, 
  // and itvalue is used as the absolute description of 
  // the current deadline of the task 
 
  // initialize first it interval with zero values 
  timerDef->it_interval.tv_sec = 0;
  timerDef->it_interval.tv_nsec = 0;

  // compute next absolute deadline from task config struct 
  unsigned long sec = wd->task_descriptor->period/1000;
  unsigned long ns = (wd->task_descriptor->period*1000 - (sec * 1000000)) * 1000;
  
  timerDef->it_value.tv_sec = start_timespec.tv_sec 
    + (wd->task_descriptor->iteration_counter+1)*sec;
  timerDef->it_value.tv_nsec = start_timespec.tv_nsec
    + (wd->task_descriptor->iteration_counter+1)*ns;
  
  if(timerDef->it_value.tv_nsec >= 1000000000) 
  {
    timerDef->it_value.tv_nsec -= 1000000000;
    timerDef->it_value.tv_sec++;
  }
  unsigned long dsec = timerDef->it_value.tv_sec-start_timespec.tv_sec;
  unsigned long dns = timerDef->it_value.tv_nsec-start_timespec.tv_nsec;
  if(dns  < 0) 
  {
    timerDef->it_value.tv_nsec += 1000000000;
    timerDef->it_value.tv_sec--;
  }

  //enable timer to wake up watchdog thread in case of deadline miss
  return timer_settime(wd->timer_id, TIMER_ABSTIME, timerDef, NULL);
} 

int cancel_wd( wd_desc_t * wd){
 struct itimerspec timerDef; 
 timerDef.it_interval.tv_sec = 0;
 timerDef.it_interval.tv_nsec = 0;
 timerDef.it_value.tv_sec = 0;
 timerDef.it_value.tv_nsec = 0;
 // this call to settime is supposed to desarm the timeout as it_value
 // is zero.
 return timer_settime(wd->timer_id, TIMER_ABSTIME, &timerDef, NULL);
}
