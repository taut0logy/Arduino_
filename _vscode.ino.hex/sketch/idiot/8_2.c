#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\8_2.c"
#include<stdio.h>
#include<stdlib.h>
int* copy_array(int* arr,int n)
{
    int* new_arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        new_arr[i]=arr[i];
    }
    return new_arr;
}
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
    int* b=copy_array(a,n);
    printf("Elements of the copied array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}