#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_Counting_Rectangles.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005][1005];
void solve()
{
    int n,q;
    cin>>n>>q;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        dp[x][y]++;
    }
    ll sum=0;
    for(int i=1;i<1005;i++)
    {
        for(int j=1;j<1005;j++)
        {
            sum+=dp[i][j]*i*j;
            dp[i][j]=sum;
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x1,y1,x2,y2,ans=0;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1+1;j<x2;j++)
        {
            ans+=dp[j][y2-1]-dp[j][y1];
        }
        cout<<ans<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}