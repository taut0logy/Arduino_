#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Partitioning_the_Array.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define fr front()
#define bc back()
#define bg begin()
#define en end()
#define gr(x) greater<x>()
#define nl "\n"
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define clr(v) v.clear()
#define mem(a, b) memset(a, b, sizeof(a))
#define yn(flag) cout << ((flag) ? "YES" : "NO") << "\n"
#define YN(flag) cout << ((flag) ? "Yes" : "No") << "\n"
#define cs cout<<"Case "<<TT<<": ";
#define cs1 cout<<"Case "<<TT<<":\n";
#define pi acos(-1)
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
const long long M=1e9+7;
const long long inf=1e18;
const long long N=1e5+5;
const long long maxn=1e6+5;
const double eps=1e-9;
const long long mod=998244353;
vi factor;
int cnt,n;
void factors(ll n)
{
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factor.pb(i);
            if(i!=n/i) factor.pb(n/i);
        }
    }
}
void can(int i,vl v)
{
    int m=sz(v)/factor[i];
    for(in)
}

void solve(int TT)
{
    factor.clear();
    cnt=0;
    cin>>n;
    vl a(n);
    int ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    factors(n);
    vector<vi> mods;
    for(int i=2;i<=n;i++)
    {
        vi v;
        for(int j=0;j<n;j++)
        {
            (v.pb(a[j]%i));
        }
        mods.pb(v);
    }
    for(auto f:factor)
    {
        int m=n/f;
        bool flag=false;
        for(int i=0;i<f;i++)
        {
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int TEST=1;
    cin>>TEST;
    for(int TT=1;TT<=TEST;TT++)
    {
        solve(TT);
    }
    return 0;
}