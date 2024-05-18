#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Umka_and_a_Long_Flight.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[50];
void fibo()
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<50;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
}
bool check(ll n,ll x,ll y)
{
    if(n==1) return true;
    if(y<=dp[n-1])
    {
        ll x1=dp[n-1]-y+1;
        ll y1=x;
        return check(n-1,x1,y1);
    }
    if(y>dp[n])
    {
        ll x1=dp[n+1]-y+1;
        ll y1=x;
        return check(n-1,x1,y1);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fibo();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        cout<<(check(n,x,y)?"YES":"NO")<<endl;
    }
    return 0;
}