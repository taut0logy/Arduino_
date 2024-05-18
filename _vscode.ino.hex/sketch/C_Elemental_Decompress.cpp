#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Elemental_Decompress.cpp"
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
    ll n;
    mll m;
    bool f=true;
    cin>>n;
    ll a[n];
    ll x[n]={0},y[n]={0},one[n+1]={0},two[n+1]={0};
    sl s1,s2;
    f(i,0,n,1)
    {
        cin>>a[i];
        m[a[i]]++;
        if(m[a[i]]>2) f=false;
    }
    if(!f)
    {
        nout;
        return;
    }
    f(i,0,n,1)
    {
        if(one[a[i]]==0)
        {
            x[i]=a[i];
            one[a[i]]=1;
        }
        else if(two[a[i]]==0)
        {
            y[i]=a[i];
            two[a[i]]=1;
        }
        else f=false;
    }
    if(!f)
    {
        nout;
        return;
    }
    f(i,0,n,1)
    {
        if(one[i+1]==0) s1.insert(i+1);
        if(two[i+1]==0) s2.insert(i+1);
    }
    f(i,0,n,1)
    {
        if(x[i]==0)
        {
            auto p=s1.upper_bound(y[i]);
            if(p==s1.bg)
            {
                f=false;
                break;
            }
            else
            {
                p--;
                x[i]=*p;
                s1.erase(p);
            }
        }
        else
        {
            auto p=s2.upper_bound(x[i]);
            if(p==s2.bg)
            {
                f=false;
                break;
            }
            else
            {
                p--;
                y[i]=*p;
                s2.erase(p);
            }
        }
    }
    if(!f)
    {
        nout;
        return;
    }
    yout;
    f(i,0,n,1) cout<<x[i]<<' ';
    cout<<endl;
    f(i,0,n,1) cout<<y[i]<<' ';
    cout<<endl;
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