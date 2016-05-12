#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc = 2)
    {
        alarm(atoi(argv[1]));
        pause();
    }
}
