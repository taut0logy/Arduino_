#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Make_It_Permutation.cpp"
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
const long long M = 1e9 + 7;
ll bigmod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll x = bigmod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2 == 1)
        x = (x * a) % m;
    return x;
}
void solve()
{
    ll n, c, d, ans1 = 0, mx = 0;
    cin >> n >> c >> d;
    mll m;
    vl a;
    ll ans=n*c+d;
    f(i, 0, n, 1)
    {
        ll y;
        cin >> y;
        if (!m[y])
            a.pb(y);
        m[y]++;
        mx = max(mx, y);
        
    }
    sort(all(a));
    //for(auto x:a) cout<<x<<' ';
    //cout<<endl;
    /* if(mx==a.back())
    {
        cout<<0<<endl;
        return;
    } */
    vl v;
    m.clear();
    for(int i=0;i<a.size();i++)
    {
        if(m[a[i]]) continue;
        m[a[i]]++;
        v.pb(a[i]);
        ll x=(n-v.size())*c +(v[i]-v.size())*d;
        ans=min(ans,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(m[i]) ans1++;
        ll y=(n-ans1)*c +(i-ans1)*d;
        ans=min(ans,y);
    }
    cout<<ans<<endl;
    /* ll ans2 = ans1;
    ll ans3 = ans1;
    ll ans4 = ans1;
    // cout<<ans1<<endl;
    ans1 += d * (mx - sz(a));
    sort(all(a));
    if(sz(a)==a.back())
    {
        cout<<0<<endl;
        return;
    }
    ll cnt = 0;
    ans2 += c * (sz(a));
    ans2 += d;
    // if(a[0]!=1) ans2+=d;
    // ans3=ans2;
    
    for (int i = 1; i < a[0]; i++)
    {
        a.pb(i);
        m[i]++;
        ans3 += d;
        ans4 += d;
    }
    sort(all(a));
    /* for (auto x : a)
         cout << x << " ";
     cout << endl; */
    /* cnt = 0;
    int i = 0;
    while(a[i]==i+1)
    {
        cnt++;
        i++;
    }
    ans3 += c * (sz(a) - cnt);
    ans4+=c*(sz(a)-cnt+1);
    if(i+1<sz(a))ans4 += d * (a[i+1] - a[i]);
    else ans4=INT_MAX;
    //cout<<ans1<<' '<<ans2<<' '<<ans3<<' '<<ans4<<endl;
    cout <<min( min(min(ans1, ans2), ans3),ans4) << endl; */
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