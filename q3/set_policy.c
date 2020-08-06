#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <sys/syscall.h>
#include <linux/kernel.h>

struct sched_attr
{
   unsigned int size; 
   unsigned int sched_policy; // Policy (CHED_*)
   unsigned int sched_flags; // flags
   unsigned int sched_nice; // Nice value (SCHED_OTHER SCHED_BATCH)
   unsigned int sched_priority; //Static priority SCHED_FIFO, SCHED_RR
    /*Reaining fields are for SCHED_DEADLINE */
   unsigned int sched_runtime;
   unsigned int sched_deadline;
   unsigned int sched_period;
};

int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
    return syscall(__NR_sched_setattr, pid, attr, flags);
}

int main(int argc, char *argv[]){

    int pid = getpid();
	int policy = atoi(argv[1]);
	int priority = atoi(argv[2]);
	struct sched_param p = {.sched_priority = priority};
	int result;

    switch(policy)
    {
        case (SCHED_OTHER):
			printf("pid:%d\n",getpid());
			result = sched_setscheduler(getpid(), policy, &p);
            break;
        case (SCHED_FIFO):
			result = sched_setscheduler(getpid(), policy, &p);
            break;
		case (SCHED_RR):
			result = sched_setscheduler(getpid(), policy, &p);
            break;
		case (SCHED_BATCH):
			result = sched_setscheduler(getpid(), policy, &p);
            break;
		case (SCHED_IDLE):
			result = sched_setscheduler(getpid(), policy, &p);
            break;
		case (SCHED_DEADLINE):{
			struct sched_attr sched;
			sched.size = sizeof(sched);
			sched.sched_priority = 0;
			sched.sched_flags = 0;
			sched.sched_policy = SCHED_DEADLINE;
			sched.sched_period = 30000;
			sched.sched_deadline = sched.sched_period;
			sched.sched_runtime = 20000;
			result = sched_setattr(getpid(), &sched, 0);
			priority = 0;
			}
			
    
	}
	if (result == 0){
		printf("Process id: %d\n", getpid());
		printf("Scheduling successfully set to: %d\n", sched_getscheduler(0));
		printf("Priority set to: %d\n", priority);
	}
	if (result == -1){ 

	switch(errno)
	{
		case EINVAL:
			puts("The parameters are not valid");
			break;
		case EPERM:
			puts("You don't have the permission for such a queurie");
			break;
		case ESRCH:
			puts("PID not found");
			break;
	}
 }
	while(1);
	return 0;

}