#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\4_1.c"
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int factorial=1;
    for(int i=1;i<=n;i++)
    {
        factorial=factorial*i;
    }
    printf("Factorial of %d is %d",n,factorial);
    return 0;
}