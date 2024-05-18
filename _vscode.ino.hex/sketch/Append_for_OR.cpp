#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Append_for_OR.cpp"
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
const ll M = 1e9 + 7;
void solve()
{
    ll n,y,x=0;
    cin>>n>>y;
    ll aa[n];
    f(i,0,n,1)
    {
        cin>>aa[i];
        x|=aa[i];
    }
    if(x==y)
    {
        cout<<0<<endl;
        return;
    }
    if(x==0)
    {
        cout<<y<<endl;
        return;
    }
    ll X=x,Y=y;
    vl xx,yy;
    while(x)
    {
        xx.pb(x%2);
        x/=2;
    }
    while(y)
    {
        yy.pb(y%2);
        y/=2;
    }
    ll l1=xx.size(),l2=yy.size();
    f(i,0,l2-l1,1)
    {
        xx.pb(0);
    }
    /* ff(x,xx) cout<<x;
    cout<<endl;
    ff(x,yy) cout<<x;
    cout<<endl;  */
    if(yy.size()<xx.size())
    {
        cout<<-1<<endl;
        return;
    }
    
    f(i,0,yy.size(),1)
    {
        if(yy[i]==0 && xx[i]==1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    ll ans=X^Y;

    cout<<ans<<endl;
    
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