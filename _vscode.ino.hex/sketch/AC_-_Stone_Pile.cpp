#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AC_-_Stone_Pile.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dp[27][100007*20];
ll n,a[27];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=sum;j++)
        {
            if(dp[i][j])
            {
                dp[i+1][j]=true;
                if(j+a[i]<=sum) dp[i+1][j+a[i]]=true;
            }
        }
    }
    ll ans=INT_MAX;
    for(ll i=0;i<=sum/2;i++)
    {
        if(dp[n][i])
        {
            ans=min(ans,abs(sum-2*i));
        }
    }
    cout<<ans<<endl;
    return 0;
}