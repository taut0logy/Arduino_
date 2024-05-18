#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\10_1.c"
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
    int sum=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            sum+=a[i][j];
        }
    }
    printf("Sum of all the elements of the array is: %d",sum);
    return 0;
}