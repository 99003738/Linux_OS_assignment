#include<signal.h>

void handler_for_int(int signo) {
  printf("Hangup\n");
}
int main() 
{
  printf("Welcome\n");// getpid());
  signal(SIGHUP, handler_for_int);
  while(1)
    pause();  
  return 0;
}