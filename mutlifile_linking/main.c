#include "common.h"


int main()
{
	pid_t ret=0; 
    ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		int k;
		  printf("\nHi,");
        k=execlp("./wc.out",NULL);
        if(k<0)
		{
			perror("execlp");
			exit(1);
		}
	}
	else	
	{
        pid_t status;
        waitpid(-1,&status,0);
      
	}
	return 0;
}