#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Hex-a-bonacci.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M=10000007;
ll dp[10005];
ll a,b,c,d,e,f,n;
ll fn(ll n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%M;
}
int main()
{
    int n,cases;
    cin>>cases;
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<caseno<<": "<<fn(n)%M<<endl;
        //clear(dp);
    }
}