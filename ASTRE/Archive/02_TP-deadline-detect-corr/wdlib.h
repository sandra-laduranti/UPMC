#ifndef __WDLIB_H__
#define __WDLIB_H__

#include "threads_ports.h"
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include "threads_ports.h"

int global_init_wd();
int local_init_wd( wd_desc_t * wd, periodic_thread_config_t * td);
int set_wd( wd_desc_t * wd);
int cancel_wd( wd_desc_t * wd);

#endif
