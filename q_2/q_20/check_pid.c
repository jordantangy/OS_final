#include <signal.h>
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 


void check_pid(int pid){

    int num = getpgid(pid);
    if(num == 0) printf("Process %d exists\n",pid);
    //errno is a variable from the library errno.h that indicates that an error occured.
    switch(errno){
        //EPERM , variable that indicates that the operation is not permitted.  
        case EPERM:
        printf("Process %d exists but we have no permission \n",pid);
        break;
        //process doesnt exist at all
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