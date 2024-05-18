#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Lamps.cpp"
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
bool comp(pll a,pll b)
{
    if(a.ff==b.ff)
        return a.ss>b.ss;
    return a.ff<b.ff;
}
void solve()
{
    ll n;
    cin>>n;
    map<ll,vl> m;
    vector<pll> v;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        //m[a].pb(b);
        v.pb({a,b});
    }
    //ll ans=0;
    /* for(auto x:m)
    {
        sort(all(x.ss),gr);
        m[x.ff]=x.ss;
    } */
    sort(all(v),comp);
    ll ans=0,cur=0,br=0;
    ll pos=0;
    while(cur<n)
    {
        ans+=v[cur].ss;
        br++;
        ll x=0;
        while(pos<n && v[pos].ff<=br)
        {
            x++;
            pos++;
        }
        if(cur+1<pos)
        {
            br=0;
            cur=pos-1;
        }
        else br-=x;

        cur++;
    }
    /* for(auto x:m)
    {
        for(auto y:x.ss)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    } */
    /* ll br=0;
    for(ll cur=1;cur<=n;cur++)
    {
        for(ll i=0;i<sz(m[cur]);i++)
        {
            if(i>=cur)
            {
                break;
            }
            else
                ans+=m[cur][i];
        }
    } */
    /* for(auto x:v)
    {
        cout<<x.ff<<" "<<x.ss<<endl;
    }
    ll br=0;
    for(auto x:v)
    {
        if(br==x.ff)
        {
            continue;
        }
        if(cur>=x.ff)
        {
            br=x.ff;
            cur-=lb(all(v),x)-v.begin();
        }
        else
        {
            cur++;
            ans+=x.ss;
        }
    } */
    cout<<ans<<endl;
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
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}