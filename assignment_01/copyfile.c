#include "common.h"

int main(int argc, char *argv[])
{
	int fd,nbytes,nbytes1,fd1;
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(1);
	}
    int len=strlen(buf);
    fd1 = open(argv[2],O_WRONLY|O_CREAT,0666);
    nbytes1= write(fd1, buf, len);//system call file descriptor
	if(nbytes1<0)
	{
		perror("write");
		exit(2);
	}
	printf("written successfully,nbytes=%d\n",nbytes1);
	close(fd1);
	close(fd);
	return 0;	//exit(0);
}