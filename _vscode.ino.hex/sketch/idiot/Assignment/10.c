#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\10.c"
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j%2) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}