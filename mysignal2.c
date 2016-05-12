#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void catcher()
{
    printf("caught\n");
    exit(0);
}

void catcher2()
{
    printf("caught2\n");
    exit(0);
}


main(int argc,char *argv[])
{
        // signal(SIGINT,catcher);
    signal(SIGQUIT,catcher2);
    
    if(argc==1)
    {
        while(1)
            printf("y\n");
    }
    else
    {
        while(1){
            printf("%s\n",argv[1]);
        }
    }
}
