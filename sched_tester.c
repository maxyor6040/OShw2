// sched_tester.c - Testing file 

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "hw2_syscalls.h"

int fibonaci(int n); 

struct sched_param{
  int sched_priority;
  int requested_time;
  int trial_num;

};

// The main program 
// Note that according to piaza we can assume that the number of args is valid 

int main(int argc, char** argv){
	int num_of_processes = argc / 2;
	int i=1;
	pid_t father_pid = getpid();
	printf ("Father pid is: %d/n" , father_pid);
	for (; i <= num_of_processes ; i++){
		struct sched_param* new_param = malloc (sizeof (*new_param));
		// gets the fibonaci number for calculation of the ith process
		int n = atoi(argv[2*i]);		
		// gets the number of trials of the ith process
		new_param->trial_num = atoi(argv[2 * i - 1]);
		new_param->sched_priority = 0;
		// Note: according to piazza we can choose whatever we want for requested_time.
		// It is recommended to try a short period of time and a long one. 
		new_param->requested_time = 2000;		
		pid_t new_pid = fork();
		if (new_pid == 0) { //son
			int retval = sched_setscheduler(getpid(), 4, new_param);
			if( retval  != 0) 
			  {
			  printf ("retval is: %d\n",retval);
				printf("An error occured on setting the policy");
				exit(1);
			}
			sleep(1);
			fibonaci(n);
			exit(0);
		}
	}
	if(father_pid == getpid()) 
		while (wait(0) != -1);
	struct switch_info* si = malloc(150 * sizeof (*si));
	get_scheduling_statistic(si); 
	// printing the results' data 
	for (i=0; i < 150; i++){
		printf ("=========================");
		printf ("No.%d: prev_pid: %d,next_pid: %d, prev_policy: %d, next_policy: %d, time: %d, reason: %d ",
				i, si[i].previous_pid, si[i].next_pid, si[i].previous_policy, si[i].next_policy, si[i].time, si[i].reason);
		printf ("=========================\n");
	}
}


// Ths function calculates the n-th fibonaci number 
int fibonaci(int n)
{
	if (n < 2)
		return n;
	return fibonaci(n-1) + fibonaci(n-2);
}

