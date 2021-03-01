#include "common.h"


void welcome()
{
    printf("\nWelcome");
}
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
        k=execlp("./l.out",NULL);
        if(k<0)
		{
			perror("execlp");
			exit(1);
		}
	}
	else	
	{
		welcome();
	}
	return 0;
}