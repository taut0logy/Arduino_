#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\V_-_Exponentiation_II.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M=1e9+7;
ll bigmod (ll a, ll b, ll m)
{
    if(a==0)
        if(b==0)
            return 1;
        else
            return 0;
    if (b == 0)
        return 1;
    ll x = bigmod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2 == 1)
        x = (x * a) % m;
    return x;
}
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=bigmod(b,c,M-1);
    ans=bigmod(a,ans,M);
    cout<<ans<<endl;
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