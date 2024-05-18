#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\All_Possible_Increasing_Subsequences.cpp"
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
const long long M=1e9+7;
const long long INF=1e18;
const long long N=1e5+5;
const double pi=acos(-1);
const double eps=1e-9;
const long long mod=998244353;
const long long mod2=1000000009;
void build(vl &tree,int ind,int l,int r,vl &v)
{
    if(l==r)
    {
        tree[ind]=1;
        return;
    }
    int mid=(l+r)/2;
    build(tree,2*ind+1,l,mid,v);
    build(tree,2*ind+2,mid+1,r,v);
    
}
void solve()
{
    int n;
    cin>>n;
    vi v(n);
    for(auto &x:v)
        cin>>x;
    vl tree(4*n);
    /* vl dp(n+1,1);
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(v[i]>v[j])
                dp[i]+=dp[j];
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
        ans+=dp[i];
    cout<<ans<<endl; */
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}