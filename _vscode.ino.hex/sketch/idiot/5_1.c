#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\5_1.c"
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int isprime;
    if(n%2==0)
    {
        if(n==2)
        {
            isprime=1;
        }
        else
        {
            isprime=0;
        }
    }
    else
    {
        isprime=1;
        for(int i=3;i<=sqrt(n);i=i+2)
        {
            if(n%i==0)
            {
                isprime=0;
                break;
            }
        }
    }
    if(isprime==1)
    {
        printf("%d is a prime number",n);
    }
    else
    {
        printf("%d is not a prime number",n);
    }
    
    return 0;
}