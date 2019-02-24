#include "threads_dispatch.h"
#include "wdlib.h" 

#ifdef DEBUG
#include <stdio.h>
#endif

struct timespec start_timespec;

int create_fp_thread (unsigned int priority,
		      unsigned int stack_size,
		      void* (*start_routine)(void),
		      pthread_t * tid,
		      int policy)
{
  int                sys_ret;
  pthread_attr_t     attr;
  struct sched_param param;

  sys_ret = pthread_attr_init (&attr);
  if (sys_ret != 0)
    {
#ifdef DEBUG
      printf("Error: thread attr init %d\n", sys_ret);
#endif
      return sys_ret;
    }

  pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

  sys_ret = pthread_attr_setscope (&attr, PTHREAD_SCOPE_SYSTEM);
  if (sys_ret != 0)
    {
#ifdef DEBUG
      printf("Error: thread attr set scope %d\n", sys_ret);
#endif
      return sys_ret;
    }
  
  if (stack_size != 0)
    {
      // On some systems, pthread_attr_setstacksize() can fail with the error
      // EINVAL if stacksize is not a multiple of the system page size.
      sys_ret = pthread_attr_setstacksize (&attr, stack_size);
      if (sys_ret != 0)
	{
#ifdef DEBUG
          printf("Error: thread attr set stack size %d\n", sys_ret);
#endif
	  return sys_ret;
	}
    }

  sys_ret = pthread_attr_setschedpolicy(&attr, policy);
  if (sys_ret != 0)
    {
      return sys_ret;
    }

  param.sched_priority = priority;
  sys_ret = pthread_attr_setschedparam (&attr, &param);
  if (sys_ret != 0)
  {
#ifdef DEBUG
    printf("Error: thread attr set sched param %d\n", sys_ret);
#endif
    return sys_ret;
  }



  sys_ret = pthread_create (tid, &attr, (void* (*)(void*))start_routine, NULL);
  return sys_ret;

}

int init_sporadic_config (thread_config_t * config)
{
  sporadic_thread_config_t info = config->sporadic_config;
  int ret =  pthread_mutex_init(info.global_q->rez, NULL);
  ret = pthread_cond_init(info.global_q->event, NULL);
  return ret;
}

int init_periodic_config (thread_config_t * config)
{
  periodic_thread_config_t * info = &config->periodic_config;
  // insert watchdog local configuration : initialize descriptor to ensure that each task deadline miss could be detected. 
  // need to be done here to capture the task configuration. watchdog descriptor into task configuration, and ensure wd descirptor has access to task configuration
  local_init_wd(&info->wd, info); 
  return 0;
}


StatusType await_periodic_dispatch(thread_config_t * config)
{
  periodic_thread_config_t * info = &config->periodic_config;
  struct timespec periodic_timespec;
  unsigned long msec = info->period;
  unsigned long ns = (info->period*1000 - (msec * 1000)) * 1000;
  int slret; // return code for nanosleep
  info->iteration_counter++;
  
  int periodic_sec = start_timespec.tv_sec+ info->iteration_counter*msec/1000;
  int periodic_nsec = start_timespec.tv_nsec+ info->iteration_counter*ns;

  while(periodic_nsec >= 1000000000) {
    periodic_nsec -= 1000000000;
    periodic_sec++;
  }
  
  while(periodic_nsec < 0) {
    periodic_nsec += 1000000000;
    periodic_sec--;
    printf("ERROR %d, %d\n", periodic_sec, periodic_nsec);
  }

  periodic_timespec.tv_sec = periodic_sec;
  periodic_timespec.tv_nsec = periodic_nsec;

  
  cancel_wd(&info->wd); 
  slret=clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &periodic_timespec, NULL);
  return slret;
}

StatusType await_sporadic_dispatch(thread_queue_t * global_q)
{
  thread_config_t * config = global_q->task;
  sporadic_thread_config_t * info = &config->sporadic_config;

  StatusType status = E_OK;
  // wait next period
  if(info->timing_wait_phase)
  {
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, info->sporadic_timespec, NULL);
  }
  info->timing_wait_phase = 1;

  // wait for messages
  status = pthread_mutex_lock(info->global_q->rez);
  if (status != E_OK)
    return status;

  if(info->global_q->msg_nb==0)
  {
    info->global_q->waiting=info->global_q->waiting+1;
    pthread_cond_wait(info->global_q->event, info->global_q->rez);
    info->global_q->waiting=info->global_q->waiting-1;
  }

  struct timespec sporadic_time_interval;
  unsigned long sec = info->time_interval/1000;
  unsigned long ns = (info->time_interval*1000 - (sec * 1000000)) * 1000;

  clock_gettime(CLOCK_MONOTONIC, &sporadic_time_interval);

  info->sporadic_timespec->tv_sec = sporadic_time_interval.tv_sec+sec;
  info->sporadic_timespec->tv_nsec = sporadic_time_interval.tv_nsec+ns;

  pthread_mutex_unlock(info->global_q->rez);
  return status;
}

void set_start_time()
{
  clock_gettime(CLOCK_MONOTONIC, &start_timespec);
}

void display_relative_date(char * id, unsigned long iteration)
{
  struct timespec current_timespec;
#ifdef DEBUG
  clock_gettime(CLOCK_MONOTONIC, &current_timespec);
  long sec = current_timespec.tv_sec-start_timespec.tv_sec;
  long nsec = current_timespec.tv_nsec-start_timespec.tv_nsec;

  if(current_timespec.tv_nsec >= 1000000000) {
    nsec -= 1000000000;
    sec++;
  }
  if(nsec  < 0) 
  {
    nsec += 1000000000;
    sec--;
  }


  printf("%s - date: %ld sec: %ld nsec - iteration %ld\n", id, sec, nsec, iteration);
#endif
}
