#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Don_t_Let_Them_Pass.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int x;cin>>x;
            if(x) a[j+1]=i+1;
        }
    int dp[n+2][m+2];
    int ans=1e9;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m+1;i++)
    {
        dp[0][i]=dp[n+1][i]=1e9;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j][i]=min({dp[j-1][i-1],dp[j][i-1],dp[j+1][i-1]})+abs(a[i]-j);
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dp[i][m]);
    }
    cout<<ans<<endl;
    return 0;
}