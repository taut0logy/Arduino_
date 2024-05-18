#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_-_Classical_Counting.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e6 + 7;
ll fact[100005];
ll inv[100005];
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
ll modPow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}
ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    return modDivide(fact[n], (fact[r] * fact[n - r]) % mod, mod);
}
void pre()
{
    fact[0] = 1;
    for (ll i = 1; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    inv[100004] = modInverse(fact[100004], mod);
    for (ll i = 100003; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    if(n*m<k)
    {
        cout<<0<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<nCr(n,k)<<endl;
        return 0;
    }
    ans=(nCr(n+k-1,k)*nCr(m,k))%mod;
    cout<<ans<<endl;
    return 0;
}