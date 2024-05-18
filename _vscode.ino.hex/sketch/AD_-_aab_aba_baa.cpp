#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AD_-_aab_aba_baa.cpp"
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
ll dp[65][65];
ll ncr(ll n,ll r)
{
    if(n==r || r==0)
        return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    ncr(62,62);
    ll a,b,x;
    cin>>a>>b>>x;
    ll n=a+b;
    for(ll i=0;i<n;i++)
    {
        if(a>0)
        {
            ll cnt=ncr(a+b-1,a-1);
            if(cnt>=x)
            {
                cout<<"a";
                a--;
            }
            else
            {
                cout<<"b";
                b--;
                x-=cnt;
            }
        }
        else
        {
            cout<<"b";
            b--;
        }
    }

    return 0;
}