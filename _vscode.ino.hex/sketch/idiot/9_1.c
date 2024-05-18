#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\9_1.c"
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a,const void* b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    int dup=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            dup++;
        }
    }
    printf("Number of duplicate elements in the array are: %d",dup);
    return 0;
}