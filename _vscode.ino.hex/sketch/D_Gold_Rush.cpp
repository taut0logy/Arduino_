#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Gold_Rush.cpp"
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
ll n,m;
mll mp;
bool check(ll x,ll m)
{
    if(x==m)
    {
        return true;
    }
    if(x%3) return false;
    if(x<m) return false;
    return check(2*x/3,m)||check(x/3,m);
}
mll prime_factor(ll n)
{
    mll mp;
    mp[1]=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                mp[i]++;
                n/=i;
            }
        }
    }
    if(n>1)
    {
        mp[n]++;
    }
    return mp;
}
/* bool eql(mll a,mll b)
{
    if(sz(a)!=sz(b))
    {
        return false;
    }
    for(auto i:a)
    {
        if(i.ss!=b[i.ff])
        {
            return false;
        }
    }
    for(auto i:b)
    {
        if(i.ss!=a[i.ff])
        {
            return false;
        }
    }
    return true;
} */
ll num(mll m)
{
    ll ans=1;
    for(auto i:m)
    {
        ans*=pow(i.ff,i.ss);
    }
    return ans;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    yn(check(n,m));
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