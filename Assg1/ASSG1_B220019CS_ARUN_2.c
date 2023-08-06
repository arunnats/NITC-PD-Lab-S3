#include <stdio.h>

void number(int n, int stop)
{
    if(n>=stop)
    {
        printf("%d",n);        
        if(n>stop)
    {
        printf(" ");
    }
    number(n-1,stop);
    }
}

void main()
{
    int num;
    scanf("%d",&num);
    number(num,1);
}