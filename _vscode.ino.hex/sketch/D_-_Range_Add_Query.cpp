#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_-_Range_Add_Query.cpp"
#include<bits/stdc++.h>
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
#define yn(flag) cout << (flag ? "Yes" : "No") << endl;
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
    ll n,k;
    cin>>n>>k;  
    ll a[n+1],sum[n+1];
    sum[0]=0;
    f(i,1,n+1,1) 
    {
        cin>>a[i];
        a[i]%=k;
        sum[i]=sum[i-1]+a[i];
        sum[i]%=k;
    }
    ll q;
    cin>>q;
    f(i,0,q,1)
    {
        ll l,r;
        cin>>l>>r;
        yn(((sum[r]-sum[l-1])%k==0));
        //cout<<sum[r]-sum[l-1]<<endl;
    }
}
int main()
{
    
    int t = 1;
   // cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}