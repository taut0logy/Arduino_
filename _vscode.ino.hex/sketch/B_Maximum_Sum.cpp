#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Maximum_Sum.cpp"
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
    ll n,k,ans=0,sum=0;
    cin>>n>>k;
    vector<ll> v(n+1);
    ll pref[n+1]={0};
    ll suf[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    sort(all(v));
    pref[0]=0;
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+v[i];
    }
    for(int i=0;i<=k;i++)
    {
        ans=max(ans,pref[n-k+i]-pref[i*2]);
    }
    
    //ans=sum-sub;
    cout<<ans<<endl;
    
}
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
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