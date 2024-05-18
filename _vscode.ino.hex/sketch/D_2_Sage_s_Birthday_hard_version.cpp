#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_2_Sage_s_Birthday_hard_version.cpp"
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
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    ll cnt=(n&1)?(n/2):n/2-1;
    for(ll i=0;i<n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<0<<endl;
        cout<<a[0]<<endl;
        return;
    }
    if(n==2)
    {
        cout<<0<<endl;
        cout<<a[0]<<" "<<a[1]<<endl;
        return;
    }
    sort(a,a+n);
    int i=cnt-1,j=n-1;
    ll ans[n];
    for(int x=0;x<n-1;x++)
    {
        if(x&1) ans[x]=a[i--];
        else ans[x]=a[j--];
    }
    ans[n-1]=a[j--];
    cnt=0;
    for(int i=1;i<n-1;i++)
    {
        if(ans[i]<ans[i-1] && ans[i]<ans[i+1]) cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        //cout<<"Case "<<TT<<": ";
        solve();
    
    return 0;
}