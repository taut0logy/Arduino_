#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dp_toky_03.cpp"
#include <bits/stdc++.h>
using namespace std;
//minimum number of coins to make a sum
//O(n*x)
int dp[1000005];
vector<int> coins;
int count(int x)
{
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    if(dp[x]!=-1) return dp[x];
    int ans=INT_MAX;
    for(auto c:coins)
    {
        if(x-c>=0)
        {
            ans=min(ans,count(x-c)+1);
        }
    }
    return dp[x]=ans;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    int x;
    cin>>x;
    memset(dp,-1,sizeof(dp));
    cout<<count(x)<<endl;
    coins.clear();
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