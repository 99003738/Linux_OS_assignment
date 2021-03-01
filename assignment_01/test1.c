#include "common.h"

int main() {
     char line[100];  //get command line
    char* argv[100];        //user command
    char* path= "/bin/";    //set path at bin
    char progpath[20];      //full file path
    int argc;   

  /*  strcpy(line,"man");
    strcat(line," ");
    strcat(line,"--help");
    */ // scanf("%s",line);
      fgets(line, 100, stdin); //get command and put it in line

  char *token;                  //split command into separate strings
    token = strtok(line," ");
    int i=0;
    while(token!=NULL){
        argv[i]=token;      
        token = strtok(NULL," ");
        i++;
    }
    argv[i]=NULL;
    
    for(int j=0;j<i;j++)
    {
          strcpy(progpath, path);           //copy /bin/ to file path
          strcat(progpath, argv[0]);            //add program to path

    printf("\nj = %d,argv = %s",j,argv[j]);
    }
    pid_t ret;
        ret=fork();
        if(ret==0)
        {
            int k;
            k=execvp(progpath,argv);
           /* char* tar[100];
            strcpy(tar[0],"man");
            strcpy(tar[1],"3");
            strcpy(tar[2],"sleep");
            tar[3][0]=NULL;
            execl("/bin/man",&tar,NULL);*/
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
          waitpid(-1,&status,0);
          printf("\nExit status %d",WEXITSTATUS(status));
       }
      else
      { 
        perror("fork error");
         exit(3);
       }
    
  return 0;
}