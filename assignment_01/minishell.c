#include<signal.h>


int main(int argc,char *argv[])
{
	
    pid_t cpid;
    int max_size =100;
    char cmd[max_size]; //cmd is for full command line
    char *usercmd[max_size];
    int i=0;
    while(1)//10 for max it can 10 cmds
    {
        //memset(usercmd,0,max_size*max_size);
       //  memset(cmd,0,max_size);
        printf("\n\nEnter Shell command:");
        scanf("%s",cmd);
         printf("\ncmd0 = %s",cmd);

        char *token = NULL;                  //split command into separate strings
        token = strtok(cmd," ");
        int i=0;
      
        while(token!=NULL)
        {
              printf("\ntoken1 = %s",token);
               printf("\ncmd1 = %s",cmd);
            usercmd[i]=token;  
            
             printf("\ni = %d,cmd = %s",i,usercmd[i]);    
            token = strtok(NULL," ");
              printf("\ntoken2 = %s",token);
              printf("\ncmd2 = %s",cmd);
            i++;
           
        }
     usercmd[i]=NULL;
       usleep(100);
        pid_t ret;
        ret=fork();
        if(ret==0)
        {
            int k;
            k=execlp(cmd,usercmd,NULL);
		    if(k<0)
		    {
			    perror("execlp");
			    exit(2);
		    }
            exit(0);
        }
        else
        if(ret>0)
       {
          int status;
          cpid=waitpid(-1,&status,0);
          printf("\nExit status %d",WEXITSTATUS(status));
       }
      else
      { 
        perror("fork error");
         exit(3);
       }
    }
}