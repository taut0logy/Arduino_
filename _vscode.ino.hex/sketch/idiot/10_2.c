#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\10_2.c"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("Enter the elements of the array: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sum[r];
    for(int i=0;i<r;i++)
    {
        sum[i]=0;
    }
    for(int i=0;i<r;i++)
    {
        int s=0;
        for(int j=0;j<c;j++)
        {
            s+=a[i][j];
        }
        sum[i]=s;
    }
    for(int i=0;i<r;i++)
    {
        printf("Sum of row %d is: %d\n",i+1,sum[i]);
    }
    return 0;
}