#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AG_-_Coin_Change_I.cpp"
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
ll dp[1005][1005];
int n,k;
vi coins;
vl ccount;
int count(int x,int ind)
{
    if(x==0) return 1;
    if(x<0 || ind==n) return 0;
    if(dp[x][ind]!=-1) return dp[x][ind];
    ll ans=0;
    for(int i=0;i<=ccount[ind];i++)
    {
        ans=(ans+count(x-coins[ind]*i,ind+1))%100000007;
    }
    return dp[x][ind]=ans;
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
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            coins.pb(x);
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ccount.pb(x);
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<test-t<<": "<<count(k,0)%100000007<<endl;
        coins.clear();
        ccount.clear();
    }
    return 0;
}