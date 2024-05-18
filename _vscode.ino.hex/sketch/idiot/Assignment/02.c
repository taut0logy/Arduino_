#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\02.c"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int sum=0;
    int len=log10(n)+1;
    if(len==1)
    {
        sum=2*n;
        printf("Sum of first and last digit is: %d",sum);
        return 0;
    }
    int arr[len];
    for(int i=0;i<len;i++)
    {
        arr[i]=n%10;
        n/=10;
    }
    sum=arr[0]+arr[len-1];
    printf("Sum of first and last digit is: %d",sum);

}