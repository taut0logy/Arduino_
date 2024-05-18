#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Showstopper.cpp"
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
    ll n;
    cin>>n;
    ll a[n];
    ll maxa=0,maxb=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll b[n];
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[n-1]) swap(a[i],b[i]);
        if(b[i]>b[n-1]) swap(a[i],b[i]);
        maxa=max(maxa,a[i]);
        maxb=max(maxb,b[i]);
    }
    /* for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    cout<<endl;
    cout<<maxa<<" "<<maxb<<endl; */
    if(a[n-1]>=maxa && b[n-1]>=maxb) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //cout<<"NO"<<endl;
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