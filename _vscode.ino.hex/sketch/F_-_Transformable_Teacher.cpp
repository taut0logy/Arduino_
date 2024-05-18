#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_-_Transformable_Teacher.cpp"
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll h[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    sort(h,h+n);
    ll l[(n+1)/2+1]={0},r[(n+1)/2+1]={0};
    for(ll i=1;i<=n/2;i++)
    {
        l[i]=h[2*i-1]-h[2*i-2]+l[i-1];
        r[n/2-i]=h[n-2*i+1]-h[n-2*i]+r[n/2-i+1];
    }
    ll ans=INT_MAX;
    for(ll i=0;i<m;i++)
    {
        ll w;
        cin>>w;
        ll ind=lower_bound(h,h+n,w)-h;
        if(ind&1) ind--;
        ll y=l[ind/2]+r[ind/2]+abs(h[ind]-w);
        ans=min(ans,y);
    }
    cout<<ans<<endl;
    return 0;
}