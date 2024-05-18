#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\knapsack.cpp"
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int dp[1005][1005];
int weight[1000];
bool isTaken[1005];
int knapsack(int n,int w)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(weight[n-1]<=w)
    {
        return dp[n][w]=max(a[n-1]+knapsack(n-1,w-weight[n-1]),knapsack(n-1,w));
    }
    else
    {
        return dp[n][w]=knapsack(n-1,w);
    }
    int i=n,j=w;
    while(i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            isTaken[i-1]=true;
            j=j-weight[i-1];
        }
        i--;
    }
    return dp[n][w];
}

int knapsack_iterative(int n,int w)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max(a[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int i=n,j=w;
    while(i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            isTaken[i-1]=true;
            j=j-weight[i-1];
        }
        i--;
    }
    return dp[n][w];
}

int main()
{
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(isTaken,false,sizeof(isTaken));
    //cout<<knapsack(n,w)<<endl;
    cout<<knapsack_iterative(n,w)<<endl;
    return 0;
}