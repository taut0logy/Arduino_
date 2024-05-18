#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Long_Legs.cpp"
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
const long long N = 1e5 + 5;
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll d =a + b;
    for(int i=2;i<=d;i++)
    {
        ll x=i-1+(a+i-1)/i+(b+i-1)/i;
        d=min(d,x);
    }
    cout<<d<<endl;
    /* ll x,y,ans=0;
    cin>>x>>y;
    if(x<y) swap(x,y);
    if(y==0)
    {
        if(x%2) ans++;
        ans+=(x/2)+1;
        cout<<ans<<endl;
        return;
    }
    if(y==1)
    {
        if(x==1)
        {
            cout<<2<<endl;
            return;
        }
        ans=1;
        if(x%2) ans++;
        ans+=(x/2)+1;
        cout<<ans<<endl;
        return;
    }
    ll z=__gcd(x,y);
    if(z==y)
    {
        if(y%2) ans++;
        ans+=(y/2)+1;
        ans+=x/y;
        cout<<ans<<endl;
        return;
    }
    ll z=x%y; */
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