#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Divisor_Chain.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl
#define nout cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define fr front()
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
typedef pair<string, long long> psl;
typedef pair<long long, long long> pll;
const long long M = 1e9 + 7;
const long long INF = 1e18;
const long long N = 1e5 + 5;
const double pi = acos(-1);
const double eps = 1e-9;
const long long mod = 998244353;
vector<bool> primes(1e6+1, true);
mll prime;
void sieve()
{
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
                primes[j] = false;
        }
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (primes[i])
            prime[i] = 1;
    }
}
void solve()
{
    ll n;
    cin >> n;
    vl v;
    ll x=1;
    while(x<n)
    {
        v.pb(x);
        x*=2;
    }
    ll rem=n-v.back(),y=v.back();
    x=rem%2;
    rem-=x;
    for(int i=31;i>=0;i--)
    {
        if(rem&(1<<i))
        {
            y+=1<<i;
            v.pb(y);
        }
    }
    if(x) v.pb(n);
    reverse(all(v));
    cout << sz(v) << endl;
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test, TT = 0;
    cin >> Test;
    sieve();
    while (TT++ < Test)
    {
        // cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}