#include "common.h"

void linux1()
{
    printf("Linux");
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
		
        k=execlp("./os.out",NULL);
        if(k<0)
		{
			perror("execlp");
			exit(1);
		}
	}
	else	
	{
        linux1();
	}
	return 0;
}