#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\8_1.c"
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int max=0,second_max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            second_max=max;
            max=a[i];
        }
        else if(a[i]<max && a[i]>second_max)
        {
            second_max=a[i];
        }
    }
    printf("Second largest element in the array is %d",second_max);
    return 0;
}