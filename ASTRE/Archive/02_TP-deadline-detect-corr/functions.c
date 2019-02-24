#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "periods.h"

void simulate_exec_time(unsigned int exec_time_ns);
unsigned int get_time_ns();

int seep_cmd = 30;

#define POS_SPEED_FREQ_RATIO (SPEED_PERIOD/POS_PERIOD)

#define POS_ARRAY_SIZE (2*POS_SPEED_FREQ_RATIO)

unsigned long position_array[POS_ARRAY_SIZE];

#define A_HUNDRED_MILLISEC 100000000
#define TEN_MILLISEC 10000000

/**************** POSITION **************/
unsigned char pos_iter=0;
unsigned char pos_offset=0;
unsigned long current_pos=0;
void pos_sensor_fct ()
{
  // simulate a "perfect" current position
  current_pos = current_pos+seep_cmd*POS_SPEED_FREQ_RATIO;

  // compute the range of index in position_array where we 
  // should write positions
  if( pos_iter%POS_SPEED_FREQ_RATIO == 0)
    pos_offset = POS_SPEED_FREQ_RATIO - pos_offset;
  unsigned char pos_idx = pos_offset+pos_iter;

  // write current position in the shared array of positions
  position_array[pos_idx] = current_pos;
  pos_iter = (pos_iter+1)%POS_SPEED_FREQ_RATIO;

  // simulate execution time
  int i = rand_a_b(2, 3);
  unsigned int simu_time = i*TEN_MILLISEC;
  simulate_exec_time(simu_time);

}

/**************** SPEED ****************/
void speed_cmp_fct()
{
  unsigned char pos_offset_for_speed = (pos_offset+POS_SPEED_FREQ_RATIO)%POS_ARRAY_SIZE;
  unsigned int i;

  unsigned long cur_pos;
  unsigned long next_pos;
  float avg_speed=0;
  // compute speed from array of position with predefine timing
  // interval between pairs of positions
  for(i=0; i<POS_SPEED_FREQ_RATIO-1; i++)
  {
    int idx = pos_offset_for_speed+i;
    cur_pos = position_array[idx];
    next_pos = position_array[idx+1];
    avg_speed += (next_pos-cur_pos)/POS_SPEED_FREQ_RATIO;
  }
  avg_speed = avg_speed/(POS_SPEED_FREQ_RATIO-1);
  printf("computed speed %f\n", avg_speed);

  // simulate execution time
  int t_fact = rand_a_b(1, 2);
  unsigned int simu_time = t_fact*A_HUNDRED_MILLISEC;
  simulate_exec_time(simu_time);
}

/**************** OBSTACLE *************/
void obst_detect_fct()
{
  // simulate execution only
  simulate_exec_time(TEN_MILLISEC); // 10 ms;
}

/**************** TRAJ *****************/
void traject_ctrl_fct()
{
  // simulate execution only
  int i = rand_a_b(5, 25);
  unsigned int simu_time = A_HUNDRED_MILLISEC;
  int j;
  for(j=0; j<i; j++)
    simulate_exec_time(simu_time);
}

/**************** UTILS ***************/

// On suppose a<b
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

unsigned int get_time_ns()
{
  struct timespec current_time;
  clock_gettime(CLOCK_MONOTONIC, &current_time);

  unsigned int current_time_ns = (current_time.tv_sec*1000000000)
    +current_time.tv_nsec;
  return current_time_ns;
}

void simulate_exec_time(unsigned int exec_time_ns)
{
  unsigned int start_time_ns = get_time_ns();
  char reached = 0;
  while(!reached)
  {
    unsigned int current_time_ns = get_time_ns();
    if(current_time_ns - start_time_ns > exec_time_ns)
      reached = 1;
  }
}
