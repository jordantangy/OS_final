#include <signal.h>
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 


void check_pid(int pid){

    int num = kill(pid,0);
    if(num == 0) printf("Process %d exists\n",pid);
    switch(errno){
        case EPERM:
        printf("Process %d does not exist\n",pid);
        break;
        
        case ESRCH:
        printf("Process %d does not exist\n",pid);
        break;
    }
}


int main()
{
    check_pid(1);
}