#include<pthread.h>
#include "common.h"

#define max 1000
int sum[max];
int no_of_threads=max/100;

void* taskbody(int* sum)
{
	int i;
	for(i=1;i<=100;i++)
	{
		sum=sum+i;
	}
	//pthread_exit(NULL);
}

int main()
{
    int total_sum;
	pthread_t pt1[no_of_threads];	//thread handle
    for(int i=0;i<no_of_threads;i++)
    {
	    pthread_create(&pt1[i],NULL,taskbody,&sum[i]);
        pthread_join(pt1[i],NULL);
    }
    for(int j=0;j<no_of_threads;j++)
    {
        total_sum=total_sum+sum[j];
    }
    printf("sum = %d",total_sum);
	return 0;	//exit(0);
}