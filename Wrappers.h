/* Wrappers*/

/* NOTE: for each of the following new system calls we should update the relevant data in
entry.S, unistd.h and syscalls.h */ 

#include <errno.h>

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

// remaining_trails wrapper
int remaining_trails(int pid){
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
int get_scheduling_statistic(struct switch_info *){
	long __res;
	__asm__ volatile (
		"movl $246, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// switch_info -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (switch_info)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// sched_setscheduler wrapper
int sched_setscheduler(struct sched_param*){
	long __res;
	__asm__ volatile (
		"movl $247, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// sched_param -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (sched_param)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}


// sched_getscheduler wrapper
int sched_getscheduler(struct sched_param*){
	long __res;
	__asm__ volatile (
		"movl $248, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// sched_param -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (sched_param)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// sched_getparam wrapper
int sched_getparam(struct sched_param*){
	long __res;
	__asm__ volatile (
		"movl $249, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// sched_param -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (sched_param)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}

// sched_getparam wrapper
int sched_setparam(struct sched_param*){
	long __res;
	__asm__ volatile (
		"movl $250, %%eax;"		// system call number -> eax
		"movl %1, %%ebx;"		// sched_param -> ebx		
		"int $0x80;"			// system call invocation via interrupt 0x80  
		"movl %%eax,%0"			// copy the value that was returned by the system call to %0 (which is the first output operand).
		: "=m" (__res)			// output operand
		: "m" (sched_param)			// input operand 
		: "%eax","%ebx"			// we use the following registers: eax, ebx 
		);
		if ((unsigned long)(__res) >= (unsigned long)(-125)) {
			errno = -(__res); __res = -1;
		}
		return (int)(__res);
}




 
 
 