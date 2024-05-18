#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Quiz_Master.cpp"
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
void solve(int TT)
{
    int n,m;
    cin>>n>>m;
    vl v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));

    vector<vl> factors(n);
    sl s;
    for(int i=1;i<=m;i++)  s.insert(i);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j*j<=v[i];j++)
        {
            if(v[i]%j==0)
            {
                factors[i].pb(j);
                if(j*j!=v[i])
                    factors[i].pb(v[i]/j);
            }
        }
    }
    vi vis(m+1,0);
    bool samne=1;
    ll l=0,r=-1,ans=N;
    while(1)
    {
        if(samne)
        {
            r++;
            if(r>=n) break;
            for(auto x:factors[r])
            {
                if(x<=m)
                {
                    if(!vis[x])s.erase(x);
                    vis[x]++;  
                }
            }
            if(!sz(s))
            {
                ans=min(ans,v[r]-v[l]);
                samne=0;
            }
            //r++;
        }
        else
        {
            if(l>=n) break;
            for(auto x:factors[l])
            {
                if(x<=m)
                {
                    vis[x]--;
                    if(!vis[x]) s.insert(x);
                }
            }
            l++;
            if(!sz(s)) ans=min(ans,v[r]-v[l]);
            else samne=1;
        }
        //for(auto x:s) cout<<x<<" ";
        //cout<<nl;
    }
    if(ans==N) ans=-1;
    cout<<ans<<nl;
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