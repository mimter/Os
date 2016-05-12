#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char str[20];
    int childpid;
    int status;
    

    while(1)
    {
        if((childpid = fork())==0){
            execl(str,str,(char *)0);
            printf("child\n");
            exit(0);
        }
        else{
            printf("prompt> ");
            fgets(str,sizeof(str),stdin);
            str[strlen(str)-1] = "\0";
            wait(&status);
        }
    }
}
