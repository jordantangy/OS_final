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
        printf("Process %d exists but we have no permission \n",pid);
        break;
        
        case ESRCH:
        printf("Process %d does not exists\n",pid);
        break;
    }
}


int main(int argc, char *argv[])
{
    int pid = atoi(argv[1]);
    check_pid(pid);
}