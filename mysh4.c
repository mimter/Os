#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

int childpid;

void catcher()
{
    kill(childpid,SIGINT);
}

void k_kill(int a)
{
    kill(a,SIGINT);
}


int main()
{
    char str[100];
    int status;
    char *str_p,*str2[100],path_name[100];
    int i=0;

    while(1)
    {
        if((childpid = fork())==0){
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
                printf("%s ",str2[i]);
                i++;
            }
            
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
                execvp(str2[0],&str2[0]);
            }
            exit(0);
        }
        else{
            signal(SIGINT,catcher);
            wait(&status);
            printf("%04x\n",status);
        }
    }
}
