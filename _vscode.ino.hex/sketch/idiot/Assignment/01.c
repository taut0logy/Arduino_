#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\01.c"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int is_perfect(int n)
{
    int sum=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                sum+=i;
            }
            else
            {
                sum+=i+n/i;
            }
        }
    }
    if(sum==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int f=is_perfect(n);
    if(f==1)
    {
        printf("%d is a perfect number.",n);
    }
    else
    {
        printf("%d is not a perfect number.",n);
    }
    return 0;
}