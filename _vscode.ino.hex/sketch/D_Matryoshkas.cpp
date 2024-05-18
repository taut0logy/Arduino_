#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Matryoshkas.cpp"
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
ll min_sets(ll a[], ll n) 
{
    ll cnt = 1, prev = a[0];
    for (int i = 1; i < n; i++)
     {
        if (a[i] > prev)
         {
            prev = a[i];
        } else 
        {
            cnt++;
            prev = a[i];
        }
    }
    return cnt;
}
void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    mll m;
    f(i,0,n,1) 
    {
        cin>>a[i];
        //m[a[i]]++;
    }
    /* ll ans=0;
    sort(a,a+n);
    while(1)
    {
        ll f=-1,prev;
        vl v;
        for(auto x:m)
        {
            if(x.second>0)
            {
                if(f==-1)
                {
                    f=1;
                    prev=x.first;
                    v.pb(x.first);
                    m[x.first]--;
                }
                else
                {
                    if(x.first==prev+1)
                    {
                        prev=x.first;
                        v.pb(x.first);
                        m[x.first]--;
                    }
                }
            }
        }
        if(v.size()>0)
        {
            ans++;
            for(auto x:v)
            {
                m[x]--;
            }
        }
        else
        {
            break;
        }
    } */
    //cout<<ans<<endl;
    cout << min_sets(a, n) << endl;
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
        //solve();
         int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());
        int res=1,last=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]!=last+1)
            {
                res++;
                last=a[i];
            }
            else last=a[i];
        }
        cout<<res<<endl;
    }
    return 0;
}