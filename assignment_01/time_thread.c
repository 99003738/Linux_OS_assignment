#include<stdio.h>
#include<time.h>

int main()
{
    time_t currenttime;
    while(1)
    {
        time(&currenttime);
        printf("\n\nCurrent time = %s",ctime(&currenttime));
        sleep(1);
    }
    return 0;
}