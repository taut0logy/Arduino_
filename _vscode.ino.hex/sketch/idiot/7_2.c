#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\7_2.c"
#include<stdio.h>
int sum_(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sum_(n-1);
}
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int sum=sum_(n);
    printf("Sum of first %d natural numbers is %d",n,sum);
    return 0;
}