#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\knapsack_3d.cpp"
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int weight[1000];
int efficiency[1000];
int volume[1000];
int dp[1005][1005][1005];
int knapsack(int n,int w,int v) //minimum weight and volume to achieve maximum value
{
    if(n==0 || w==0 || v==0)
    {
        return 0;
    }
    if(dp[n][w][v]!=-1)
    {
        return dp[n][w][v];
    }
    if(volume[n-1]<=v && weight[n-1]<=w)
    {
        return dp[n][w][v]=max(a[n-1]+knapsack(n-1,w-weight[n-1],v-volume[n-1]),knapsack(n-1,w,v));
    }
    else
    {
        return dp[n][w][v]=knapsack(n-1,w,v);
    }
    return dp[n][w][v];
}

int knapsack_iterative(int n,int w,int v)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            for(int k=0;k<=v;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k]=0;
                }
                else if(volume[i-1]<=k && weight[i-1]<=j)
                {
                    dp[i][j][k]=max(a[i-1]+dp[i-1][j-weight[i-1]][k-volume[i-1]],dp[i-1][j][k]);
                }
                else
                {
                    dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
    }
    return dp[n][w][v];
}

int main()
{
    int n,w,v;
    cin>>n>>w>>v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>volume[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(n,w,v)<<endl;
    cout<<knapsack_iterative(n,w,v)<<endl;
    return 0;
}
