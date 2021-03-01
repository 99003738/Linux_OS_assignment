#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

#define max_size 100

int stack[max_size];
int top=-1;

void push();
void pop();

int main()
{
	int ret,i,max=10,status;
	sem_t *ps,*qs;

	ps=sem_open("/s1",O_CREAT, 0666, 1);
	qs=sem_open("/s2",O_CREAT, 0666, 0);

	ret=fork();
	if(ret==0)
	{
		sem_wait(ps);
		for(i=1;i<=max;i++)
		{
			push();
			sleep(1);
		}
		sem_post(ps);
		sem_post(qs);
		exit(0);
	}
	else	//ret>0
	{
        sem_wait(qs);
	    sem_wait(ps);	
        for(i=1;i<=max;i++)
		{
			pop();
			sleep(1);
		}
		sem_post(ps);
		waitpid(-1,&status,0);
		sem_unlink("s1");
		sem_unlink("s2");
	}
	return 0;
}
void push()
{
    top++;
    stack[top]=1000;
    printf("The pushed element is %d\n",stack[top]);   
}
void pop()
{
    printf("The popped element is %d\n",stack[top]);
    top--;
}
/** TODO:- locate named semaphore in /dev/shm before unlinking */
