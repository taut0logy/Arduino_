#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_LuoTianyi_and_the_Table.cpp"
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
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll ar[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n*m);
    ll a=ar[0],b=ar[1],x=ar[n*m-1];
    ll ans=max((n-1)*(x-a)+(m-1)*(x-b),(n-1)*(x-b)+(m-1)*(x-a));
    ans+=(n*m-n-m+1)*(x-min(a,b));
    a=ar[n*m-1],b=ar[n*m-2],x=ar[0];
    ll ans2=max((n-1)*(a-x)+(m-1)*(b-x),(n-1)*(b-x)+(m-1)*(a-x));
    ans2+=(n*m-n-m+1)*(max(a,b)-x);
    ans=max(ans,ans2);
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