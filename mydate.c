#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char buf[BUFSIZ];
    time_t tval;
    struct tm *pTime;

    tval = time(NULL);
    pTime = localtime(&tval);

    printf("%d\n",tval);
    strftime(buf,sizeof(buf),"%a %b %e %H %M %S %Z %Y",pTime);
    printf("%s\n",buf);
}

    
    
