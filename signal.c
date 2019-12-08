/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarm(1); //exit after printing
}

void handler_time(int signum){ //execution time handler
  double amount_time;
  clock_t start = clock(); //start the clock
  signal(SIGALRM, handler); 
  clock_t end = clock(); 
  amount_time += (double)(end - start) / CLOCKS_PER_SEC;
  printf("Total execution time in seconds: %f\n", amount_time);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handler_time); //registers handler_time to handle SIGALRM

  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    pause(); 
  } //busy wait for signal to be delivered
  return 0; //never reached
}
