#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
    int i=0;
    for(;i<10000;i++)
    {
        printf("%d %d\n",i,kill(i,0));
    }
}

    
