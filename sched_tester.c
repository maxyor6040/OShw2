// sched_tester.c - Testing file 
// Should add includes here 

#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "Wrappers.h"

// Structs' declarations
struct switch_info {
	int previous_pid;
	int next_pid;
	int previous_policy;
	int next_policy;
	unsigned long time;
	int reason;
};

struct sched_param {
	int sched_priority;
	int requested_time;
	int trial_num;
};


// The main program 

int main(int argc, char** argv){
	if (argc % 2 == 0){
		return 0;		//handling case of invalid amount of arguments 
	}
	int num_of_processes = argc / 2; 
	for (int i=1; i <= num_of_processes ; i++){
		int n = argv[2*i];		// gets the fibonaci number for calculation of the ith process
		struct sched_param* new_param = malloc (sizeof (*new_param));
		new_param->trial_num = argv[2 * i - 1];  // gets the number of trials of the ith process
		new_param->sched_priority = 0;
		new_param->requested_time = 999;		// TODO: check what requested time should be
		pid_t new_pid = fork();
		if (new_pid == 0){	// if its the father process
			setscheduler(new_pid, 4, new_param); //setting a SHORT policy
			fibonaci(n);
			wait(new_pid);
		}	
	}
	struct switch_info* si = malloc(sizeof (*si));
	get_scheduling_statistic(si);, 
	// printing the results' data 
	printf ("previous_pid: %d\n next_pid: %d\n previous_policy: %d, next_policy: %d, time: %lu, reason: %d", previous_pid, next_pid, previous_policy, next_policy, time, reason);
}


// Ths function calculates the n-th fibonaci number 
int fibonaci(int n)
{
	if (n < 2)
		return n;
	return fibonaci(n-1) + fibonaci(n-2);
}

