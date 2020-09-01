#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<signal.h>

void sender(pid_t pid, int sig_type, int numOfSignals){
    
    if(sig_type == 2){
        for (int i=0; i < numOfSignals; i++){
             kill(pid, SIGINT);
          }
	}
    else {
             kill(pid, SIGUSR1);
        }
       
}

int main (int argc, char* argv[]){

    pid_t pid = atoi(argv[1]); 
    int sig_type = atoi(argv[2]); 
    int numOfSignals = atoi(argv[3]);
    sender(pid,sig_type,numOfSignals);
}