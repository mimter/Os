#include<stdio.h>

int main()
{
    char str[20];

    while(1)
    {
        printf("prompt>");
        fgets(str,sizeof(str),stdin);
        printf("%s\n",str);
    }
}
