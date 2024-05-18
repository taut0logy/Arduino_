#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\S_-_Nastia_and_a_Good_Array.cpp"
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
    vector<vl> v;
    f(i,0,n,1)
    {
        cin>>a[i];
        
    }
    f(i,0,n-1,1)
    {
        if(__gcd(a[i],a[i+1])!=1)
        {
            ll y=min(a[i],a[i+1]);
            a[i+1]=y;
            ll x=y+1;
            if(i>0)
            for(x=y+1;x<=2*max(a[i-1],a[i+1]);x++)
            {
                if(__gcd(x,a[i+1])==1 && __gcd(x,a[i-1])==1)
                {
                    break;
                }
            }
            a[i]=x;
            v.pb({i+1,i+2,x,y});
        }
    }
    /* if(v.empty())
    {
        ll x=min(a[0],a[1]);
        ll y=x+a[0]+a[2];
        v.pb({1,2,x,y});
    } */
    cout<<sz(v)<<endl;
    for(auto x:v)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
    }
    /* f(i,0,n,1) cout<<a[i]<<" ";
    cout<<endl; */
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