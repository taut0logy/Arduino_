#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\4_2.c"
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int fibo[n];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<n;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    printf("Fibonacci series upto %d terms is: ",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",fibo[i]);
    }
    
    return 0;
}