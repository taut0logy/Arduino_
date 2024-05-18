#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AR_-_Add_One.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;
ll dp[10][200015];
ll add(ll a,ll b)
{
    if(dp[a][b]!=-1) return dp[a][b];
    if(a+b<10) return dp[a][b]=1;
    return dp[a][b]=(add(1,a+b-10)+add(0,a+b-10))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,ans=0;
        cin>>n>>m;
        while(n)
        {
            ll temp=n%10;
            ans=(ans+add(temp,m))%mod;
            n/=10;
        }
        cout<<ans<<endl;
    }
    return 0;
}