#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Distinct_Split.cpp"
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
    ll n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    vector<vl> v(n,vl(26,0));
    f(i,0,n,1)
    {
        if(i>0) v[i]=v[i-1];
        v[i][s[i]-'a']++;
    }
    vl x=v.back();
    f(i,0,n-1,1)
    {
        vl temp = x;
        f(j,0,26,1) temp[j] -= v[i][j];
        ll res = 0;
        f(j,0,26,1)
        {
            if (v[i][j])
                res++;
            if (temp[j])
                res++;
        }
        ans = max(ans,res);
    }
    /* ll a[n]={0};
    f(i,0,n,1)
    {
        sc s1(s.bg,s.bg+i);
        sc s2(s.bg+i,s.en);
        ll x=s1.size()+s2.size();
        ans=max(ans,x);
    } */
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