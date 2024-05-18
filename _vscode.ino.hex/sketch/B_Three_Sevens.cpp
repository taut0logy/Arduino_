#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Three_Sevens.cpp"
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
void solve()
{
    ll m;
    cin >> m;
    // vl win;
    sl win;
    vl ans(m);
    vl c;
    mll y;
    map<ll, vl> check;
    for (ll i = 1; i <= m; i++)
    {
        ll n;
        cin >> n;
        for (ll j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            //if(i==1) c.pb(x);
            //win.insert(x);
            check[x].pb(i);
            y[x]=max(y[x],i);
        }
    }
    for (auto x : check)
    {
        if (x.second.back() == y[x.first])
        {
            ans[x.second.back() - 1] = x.first;
        }
        //if(sz(x.second)==m) ans.pop_back();
    }
    bool flag = true;
    for (auto x : ans)
    {
        if (x == 0)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
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