#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_-_Blue_and_Red_Balls.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl;
#define nout cout << "NO" << endl;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bc back()
#define bg begin()
#define en end()
#define gr greater<>()
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<ll> sl;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> sst;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<long long, long long> pll;
const long long M=1e9+7;
ll fact[2005];
ll inv[2005];
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
ll ncr(ll n,ll r)
{
    //ll ans=(((fact[n]*inv[r])%M)*inv[n-r])%M;
    ll ans=1;
    for(ll i=0;i<r;i++)
    {
        ans=(ans*(n-i))%M;
        //ans/=i+1;
        ans=(ans*modInverse(i+1,M))%M;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,x=1,y=1;
    cin>>n>>k;
    /* fact[0]=1;
    inv[0]=1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i]=(fact[i-1]*i)%M;
        inv[i]=modInverse(fact[i],M);
    } */
    for(ll i=1;i<=k;i++)
    {
        ll ans=(ncr(n-k+1,i)*ncr(k-1,i-1))%M;
        /* ll a=((x*(n-k-i+2))%M)/i;
        ll b;
        if(i>1 && k-i>0) b=((y*(k-i))%M)/(i-1);
        else b=1;
        ll ans;
        if(k-i>0) ans=((((a*b)%M)*(k-1))%M)/(k-i);
        else ans=(a*b)%M;
        x=a;
        y=b; */
        cout<<ans<<endl;
    }
    return 0;
}