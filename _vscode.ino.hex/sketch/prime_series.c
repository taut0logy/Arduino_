#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\prime_series.c"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *a;
    a=calloc((n+1),sizeof(int));
    for(int i=2;i<=n;i++)
    {
        if(a[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                a[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
hii