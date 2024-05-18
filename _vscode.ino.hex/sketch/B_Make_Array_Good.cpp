#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Make_Array_Good.cpp"
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
    ll n,mx=INT_MIN,mn=INT_MAX;
    cin>>n;
    ll a[n];
    f(i,0,n,1)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    cout<<n<<endl;
    f(i,0,n,1)
    {
        ll x=ceil(log2(a[i]));
        x=1<<x;
        cout<<i+1<<' '<<x-a[i]<<endl;
    }
/*     ll n,cnt=0;
    cin>>n;
    ll a[n],max=INT_MIN;
    vector<pll> ans;
    f(i,0,n,1)
    {
        cin>>a[i];
        if(a[i]>max) max=a[i];
    }
    vl v;
    f(i,1,sqrt(max)+1,1)
    {
        if(max%i==0) 
        {
            v.pb(i);
        if(i*i!=max) v.pb(max/i);   
        }     
    }
    vsort(v);
    f(i,0,n,1)
    {
        if(a[i]==1 || a[i]==max) continue;
        ll x=*upper_bound(v.bg,v.en,a[i]);
        if(x-a[i]<=a[i]) ans.pb({i+1,x-a[i]});
        else
        {
            while(x-a[i]>a[i])
            {
                ans.pb({i+1,a[i]});
                x-=a[i];
            }
            ans.pb({i+1,x-a[i]});
        }
    }
    cout<<ans.size()<<endl;
    for(auto m:ans) cout<<m.first<<' '<<m.second<<endl; */
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