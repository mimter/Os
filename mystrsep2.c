#include<stdio.h>
#include<string.h>

main()
{
    char str[]="This is a pen";
    char *str_p,*str2[10];
    int i=0;
    
    str_p=str;

    while(1)
    {
        str2[i] = strsep(&str_p," ");
        if(str2[i] == NULL)
            break;
        printf("%s\n",str2[i]);
        i++;
    }    
}
