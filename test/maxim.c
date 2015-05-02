#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdio.h>     /* printf, perror */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* _exit, fork */
struct sched_param {
    int sched_priority;
    int requested_time;
    int trial_num;
};
int main(){

    struct sched_param sp;
    sp.sched_priority = 0;
    sp.requested_time = 4000;
    sp.trial_num = 5;
    printf(" --- \n %d \n --- \n ", sched_setscheduler(getpid(), 4, &sp));


    return 0;
}

