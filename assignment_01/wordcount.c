#include "common.h"

int main()
{
	int fd,nbytes,nbytes1,fd1;
	fd=open("sample.txt",O_RDONLY);
    int count_line=1;
	int count_char=0;
	int count_word=1;
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

    int i=0;
    while(buf[i]!='\0')
    {
        if(buf[i]==' ')
        {
            count_word++;
        }
        if(buf[i]=='\n')
        {
            count_line++;
            count_word++;
        }
        count_char++;
        i++;
    }

    fd1 = open("samplefile.txt",O_WRONLY|O_CREAT,0666);
    nbytes1= write(fd1, buf, len);//system call file descriptor
	if(nbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("No.of lines, No.of,No.of word,No.of characters");
    printf("\n%d  		%d 			%d",count_line,count_word,count_char);
	close(fd);
	return 0;	//exit(0);
}