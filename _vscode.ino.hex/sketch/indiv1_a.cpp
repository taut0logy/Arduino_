#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\indiv1_a.cpp"
#include<bits/stdc++.h>
using namespace std;
double dp[5005][5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    deque<double>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<double>());
    a.push_front(0);
    memset(dp,0,sizeof(dp));
    for(int i=1 ;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j-1]*a[i]+dp[i-1][j+1]*(1-a[i]);
        }
    }
    cout<<fixed<<setprecision(10)<<dp[k]<<endl;
    return 0;
}