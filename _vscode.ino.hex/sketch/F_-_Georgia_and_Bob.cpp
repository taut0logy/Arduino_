#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_-_Georgia_and_Bob.cpp"
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
    int T;
    scanf("%d",&T);
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0,sum=0;
        scanf("%d",&n);
        int i;
        int a[n+1];
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n+1);
        for(i=n;i>0;i--)
        {
            sum=sum^(a[i]-a[i-1]-1);
            i--;
        }
        if(sum) 
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