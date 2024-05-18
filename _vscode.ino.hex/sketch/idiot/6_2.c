#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\6_2.c"
#include<stdio.h>
#include<math.h>
int sum_of_digits(int n)
{
    int sum=0;
    while(n>0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int sum=sum_of_digits(n);
    printf("Sum of digits of %d is %d",n,sum);
    return 0;
}