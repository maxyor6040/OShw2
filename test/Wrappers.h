/* Wrappers*/

/* NOTE: for each of the following new system calls we should update the relevant data in
entry.S, unistd.h and syscalls.h */ 

#include <errno.h>

struct sched_param{
	int sched_priority;
	int requested_time;
	int trial_num;
};


struct switch_info
{
	int previous_pid;
	int next_pid;
	int previous_policy;
	int next_policy;
	unsigned long time;
	int reason;
};


// is_SHORT wrapper
int is_SHORT(int pid){
	long __res;
	__asm__ volatile (
		"movl $243, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// pid -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (pid)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// remaining_time wrapper
int remaining_time(int pid){
	long __res;
	__asm__ volatile (
		"movl $244, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// pid -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (pid)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// remaining_trials wrapper
int remaining_trials(int pid){
	long __res;
	__asm__ volatile (
		"movl $245, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// pid -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (pid)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// get_scheduling_statistic wrapper
int get_scheduling_statistic(struct switch_info * si){
	long __res;
	__asm__ volatile (
		"movl $246, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// switch_info -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (si)			// input operand
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}
