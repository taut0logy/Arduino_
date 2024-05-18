#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Kuriyama_Mirai_s_Stones.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
#define ff(x, m) for (auto x : m)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl;
#define nout cout << "NO" << endl;
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
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<long long, long long> pll;
void solve()
{
    ll n;
    cin>>n;
    ll a[n],b[n];
    f(i,0,n,1)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    ll c[n],d[n];
    c[0]=a[0];
    d[0]=b[0];
    f(i,1,n,1)
    {
        c[i]=c[i-1]+a[i];
        d[i]=d[i-1]+b[i];
    }
    ll m;
    cin>>m;
    while(m--)
    {
        ll x,l,r;
        cin>>x>>l>>r;
        if(x==1)
        {
            if(l==1) cout<<c[r-1]<<endl;
            else cout<<c[r-1]-c[l-2]<<endl;
        }
        else
        {
            if(l==1) cout<<d[r-1]<<endl;
            else cout<<d[r-1]-d[l-2]<<endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}