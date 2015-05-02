// sched_tester.c - Testing file 
// Should add includes here 

int main(int argc, char** argv){
	int num_of_processes = argc / 2; 
	for (int i=1; i <= num_of_processes ; i++){
		int n = argv[2*i];		// gets the fibonaci number for calculation of the ith process
		struct sched_param* new_param = malloc (sizeof (*new_param));
		new_param->trial_num = argv[2 * i - 1];  // gets the number of trials of the ith process
		new_param->sched_priority = 0;
		new_param->requested_time = 999;		// TODO: check what requested time should be
		pid_t new_pid = fork(); 
		if (new_pid != 0){ //son process
			setscheduler(new_pid, 4, new_param); //setting a SHORT policy
			fibonaci(n);
		}
		else { 	// father process
			wait(new_pid);
			break;
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

