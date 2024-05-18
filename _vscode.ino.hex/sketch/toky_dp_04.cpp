#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\toky_dp_04.cpp"
#include <bits/stdc++.h>
using namespace std;
//minimum number of coins to make a sum, with limited number of coins
//O(n*x*max(ccount))
int dp[1005][1005];
vector<int> coins;
vector<int> ccount;
int n;
int count(int ind,int x)
{
    if(ind==n)
    {
        if(x==0) return 0;
        else return INT_MAX;
    }
    if(x<0) return INT_MAX;
    if(dp[ind][x]!=-1) return dp[ind][x];
    int ans = INT_MAX;
    for(int i=0;i<=ccount[ind];i++)
    {
        ans=min(ans,count(ind+1,x-i*coins[ind])+i);
    }
    return dp[ind][x]=ans;
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ccount.push_back(x);
    }
    int x;
    cin>>x;
    memset(dp,-1,sizeof(dp));
    cout<<count(n,x)<<endl;
    coins.clear();
    ccount.clear();
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