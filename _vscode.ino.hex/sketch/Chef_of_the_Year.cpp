#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Chef_of_the_Year.cpp"
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
const ll M = 1e9 + 7;
/* void printv(vector<pair<int,string>> v)
{
    ff(x, v)
        cout << x.first << " " << x.second << endl;
    cout << endl;
} */
bool comp(pair<int, string> a, pair<int, string> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    mss mc;
    msi mn;
    msi mm;
    f(i,0,n,1)
    {
        string s,ss;
        cin>>s>>ss;
        mc[s]=ss;
    }
    f(i,0,m,1)
    {
        string s;
        cin>>s;
        mn[s]++;
        mm[mc[s]]++;
    }
    vector<pair<int,string>> vn,vm;
    ff(x,mn)
    {
        vn.pb({x.second,x.first});
    }
    ff(x,mm)
    {
        vm.pb({x.second,x.first});
    }
    sort(vn.begin(),vn.end(),comp);
    sort(vm.begin(),vm.end(),comp);
    cout<<vm[0].second<<endl<<vn[0].second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}