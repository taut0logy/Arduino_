#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Doremy_s_Perfect_Math_Class.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (int i = a; i < b; i += x)
#define fr(i, a, b, x) for (int i = a; i >= b; i -= x)
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
vl a(100000);
mll m;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void solve()
{
    int n;
    ll c,x;
    cin >> n;
    //ll a[n];
    //mll m;
    f(i, 0, n, 1)
    {   
        cin >> a[i];
    }
    x=a[0];
    f(i,1,n,1) x=gcd(a[i],x);
    c=a[n-1]/x;
    cout << c << endl;
    m.clear();
    a.clear();
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