#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<sys/param.h>
#include<signal.h>

int childpid1,childpid2;

void catcher()
{
    kill(childpid1,SIGINT);
}

void k_kill(int a)
{
    kill(a,SIGINT);
}


int main()
{
    char str[100];
    int status1,status2;
    char *str_p,*str2[100],path_name[100];
    int i=0,flag=0,fd,pipe_fd;
 
    while(1)
    {
        if((childpid1 = fork())==0){
            flag = 0;
            getwd(path_name);
            printf("%s> ",path_name);
            fgets(str,sizeof(str),stdin);
            str_p = str;
            str[strlen(str)-1] = '\0';
            while(1)
            {
                str2[i] = strsep(&str_p," ");
                if(str2[i] == '\0')
                   break;
                    //  printf("%s ",str2[i]);
                if(strcmp(str2[i],"|")==0)
                    flag = i;
                i++;
            }
            printf("%s",str2[1]);
/*
            if(flag != 0){
                if(pipe(pipe_fd) == -1){
                    perror("pipe");
                    exit(1);
                }

                str2[flag] = NULL;
                
                if((childpid2 = fork())==0){
                    execvp(argv[i+1],&argv[i+1]);
                }
                else{
                    exit(1);
                }                    
            }
*/
            if(strcmp(str2[0],"k")==0)
            {
                kill(atoi(str2[1]),SIGINT);
            }
            else if(strcmp(str2[0],"s")==0)
            {
                kill(atoi(str2[1]),SIGSTOP);
            }
            else if(strcmp(str2[0],"cd")==0){
                
                chdir(str2[1]);
            }
            else{
                execvp(str2[0],str2);
            }
            exit(0);
        }
        else{
            signal(SIGINT,catcher);
            wait(&status1);
            printf("%04x\n",status1);
        }
    }
}
