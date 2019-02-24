#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define __USE_UNIX98
#include <pthread.h>
#include <sched.h>
#include <errno.h>

#include "threads_dispatch.h"
#include "wdlib.h"
#include "periods.h"
#include "functions.h"

void pos_body();
void speed_body();
void obst_body();
void traj_body();

char reached_barrier=0;

#define NB_THREADS 4

// Initialization of data for task pos_sensor (periodic, period = 100 ms)
thread_config_t pos_info = {POS_PERIOD, 0};

// Initialization of data for task speed_cmp (periodic, period = 1000 ms)
thread_config_t speed_info = {SPEED_PERIOD, 0};

// Initialization of data for task obst_detect  (periodic, period = 50 ms)
thread_config_t obst_info = {OBST_PERIOD, 0};

// Initialization of data for task traject_ctrl  (periodic, period = 2000 ms)
thread_config_t traj_info = {TRAJ_PERIOD, 0};

pthread_mutex_t start_barrier_mutex;
pthread_cond_t start_barrier_cond;
pthread_cond_t main_barrier_cond;

#ifdef DEBUG
#include <stdio.h>
#endif

int main(int argc, char* argv[])
{
  int max_prio = sched_get_priority_max(SCHED_FIFO);
  int min_prio = sched_get_priority_min(SCHED_FIFO);

  pthread_t thId = pthread_self();
  pthread_setschedprio(thId, min_prio); // we put the main thread at
					// the min prio to make sure
					// other threads start as soon
					// as they are ready
  pthread_mutex_init(&start_barrier_mutex, NULL);
  pthread_cond_init(&start_barrier_cond, NULL);
  pthread_cond_init(&main_barrier_cond, NULL);


  global_init_wd(); // start de Wathdog thread

  init_periodic_config(&pos_info);
  init_periodic_config(&speed_info);
  init_periodic_config(&obst_info);
  init_periodic_config(&traj_info);

  pthread_t pos_tid;
  create_fp_thread(min_prio+3, 40960, (void*) pos_body, &pos_tid, SCHED_FIFO);

  pthread_t speed_tid;
  create_fp_thread(min_prio+2, 40960, (void*) speed_body, &speed_tid, SCHED_FIFO);

  pthread_t obst_tid;
  create_fp_thread(min_prio+4, 40960, (void*) obst_body, &obst_tid, SCHED_FIFO);

  pthread_t traj_tid;
  create_fp_thread(min_prio+1, 40960, (void*) traj_body, &traj_tid, SCHED_FIFO);

  pthread_mutex_lock(&start_barrier_mutex);
  while(reached_barrier<NB_THREADS)
  {
    pthread_cond_wait(&main_barrier_cond, &start_barrier_mutex);
  }
  pthread_mutex_unlock(&start_barrier_mutex);

  set_start_time();
#ifdef DEBUG
  printf("Release all tasks\n");
#endif
  
  pthread_cond_broadcast(&start_barrier_cond);

  pthread_join(pos_tid, NULL);

}


void pos_body()
{
  pthread_mutex_lock(&start_barrier_mutex);
  reached_barrier++;
  pthread_cond_signal(&main_barrier_cond);
  pthread_cond_wait(&start_barrier_cond, &start_barrier_mutex);
  pthread_mutex_unlock(&start_barrier_mutex);
  while(1)
  {
    set_wd(&pos_info.periodic_config.wd);
#ifdef DEBUG
    display_relative_date("Start thread pos_sensor", (pos_info.periodic_config).iteration_counter);
#endif
    
    pos_sensor_fct();

#ifdef DEBUG
    printf("Finish thread pos_sensor\n");
#endif

    await_periodic_dispatch(&pos_info);
  }
}

void speed_body()
{
  pthread_mutex_lock(&start_barrier_mutex);
  reached_barrier++;
  pthread_cond_signal(&main_barrier_cond);
  pthread_cond_wait(&start_barrier_cond, &start_barrier_mutex);
  pthread_mutex_unlock(&start_barrier_mutex);
  while(1)
  {
    set_wd(&speed_info.periodic_config.wd);
#ifdef DEBUG
    display_relative_date("Start thread speed_cmp", (speed_info.periodic_config).iteration_counter);
#endif
    speed_cmp_fct();
#ifdef DEBUG
    printf("Finish thread speed_cmp\n");
#endif

    await_periodic_dispatch(&speed_info);
  }
}


void obst_body()
{
  pthread_mutex_lock(&start_barrier_mutex);
  reached_barrier++;
  pthread_cond_signal(&main_barrier_cond);
  pthread_cond_wait(&start_barrier_cond, &start_barrier_mutex);
  pthread_mutex_unlock(&start_barrier_mutex);
  while(1)
  {
    set_wd(&obst_info.periodic_config.wd);
    display_relative_date("Start thread obst_detect", (obst_info.periodic_config).iteration_counter);
    obst_detect_fct();
#ifdef DEBUG
    printf("Finish thread obst_detect\n");
#endif

    int ret=await_periodic_dispatch(&obst_info);
  }
}

void traj_body()
{
  pthread_mutex_lock(&start_barrier_mutex);
  reached_barrier++;
  pthread_cond_signal(&main_barrier_cond);
  pthread_cond_wait(&start_barrier_cond, &start_barrier_mutex);
  pthread_mutex_unlock(&start_barrier_mutex);
  while(1)
  {
    set_wd(&traj_info.periodic_config.wd);
    display_relative_date("Start thread traject_ctrl", (traj_info.periodic_config).iteration_counter);
    traject_ctrl_fct();
#ifdef DEBUG
    printf("Finish thread traject_ctrl\n");
#endif

    await_periodic_dispatch(&traj_info);
  }
}

