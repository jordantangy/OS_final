#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>  
#include<signal.h> 

int counter = 0;

void SIGINT_handler() {
      ++counter;
 }

void SIGUSR1_handler() {   
    printf("The server received %d SIGINT\n", counter); 
    kill(getpid(), SIGTERM);  
   }

int main (){
   printf ("Server PID: %d \n",getpid());
   signal(SIGINT, SIGINT_handler);
   signal(SIGUSR1, SIGUSR1_handler);
   while (1){
	sleep(1);
	}	
   return(0);
}