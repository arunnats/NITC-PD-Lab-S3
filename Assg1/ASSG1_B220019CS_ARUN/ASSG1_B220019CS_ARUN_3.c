#include <stdio.h>

double factorial(int num) {
    if (num == 1 || num == 0)
     {
        return 1.0; 
    }
     else 
    {
        return num * factorial(num - 1); 
    }
}

double power(double base, int exp) {
    double ans = 1.0;
    for (int i = 0; i < exp; i++) 
    {
        ans *= base;
    }
    return ans;
}


void main()
{
    int x, n, i, multfactor=1;
    scanf("%d",&x);
    scanf("%d",&n);
    double rad_x=x*(3.1415/180.0), sum=0.0;
    for ( i = 0; i <= n; i++)
    {
        double term=(multfactor*power(rad_x,2*i+1))/factorial(2*i+1);
        sum=sum+term;
        multfactor=multfactor*-1;    
    }
    
    printf("%.4f",sum);

}