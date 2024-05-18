#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_-_Georgia_and_Bob.c"
#include<stdio.h>
#include<stdlib.h>
int a[1005];
int sum[1005];
int main(int argc, char *argv[])
{
    int T,j;
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {
        int n,ans=0;
        scanf("%d",&n);
        int i;
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=(a[i]-a[i-1]-1);
        }
        for(i=n-1;i>=0;i-=2)
        {
            ans=ans^(a[i+1]-a[i]-1);
        }
        if(ans)
        {
            printf("Georgia will win\n");
        }
        else 
        {
            printf("Bob will win\n");
        }
    }
    return 0;
}