#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "Wrappers.h"
//#include <sched.h> this should NOT be included.



int main(void) {
	/*struct sched_param x;
	x.sched_priority = 0;
	x.requested_time = 20;
	x.trial_num = 5;
	pid_t pid = fork();
	if(pid) { //father
		printf("%d\n", sched_setscheduler(pid, 4, &x));
	} else { //son
		sys
	}*/

	//TODO make sure what we send to sched_setscheduler is valid and not garbage.
	//maybe we should use copy_from_user() or something like that, if that's not done for us already.

	int i= 0, j = 0;
	struct switch_info* x = malloc(sizeof(*x)*150);
	pid_t my_pid = getpid();
	for (; j < 5; ++j) {
		pid_t pid = fork();
	}
	if (getpid() != my_pid) { //son
		exit(1);
	}
	else { //father
		int px;
		while(wait(&px)!=-1);
		get_scheduling_statistic(x);
		for (; i < 150; ++i) {
			printf("previous_pid:%d   next_pid:%d   previous_policy:%d   next_policy:%d   time:%d   reason:%d\n",
				   x[i].previous_pid, x[i].next_pid, x[i].previous_policy, x[i].next_policy, x[i].time, x[i].reason);
		}
	}

	return 0;
}
