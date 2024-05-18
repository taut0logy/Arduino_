#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Equalize_by_Divide.cpp"
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
bool chk(vector<ll> a) 
{
    f(i,0,sz(a)-1,1) if(a[i] != a[i+1]) return false;
    return true;
}
void solve()
{
    ll n;
    bool flag=true;
    cin>>n;
    vl a(n),temp(n);
    f(i,0,n,1)
    {
        cin>>a[i];
        temp[i]=a[i];
    }
    if(chk(a))
    {
        cout<<0<<endl;
        return;
    }
    vector<pll> ans;
    while(!chk(a))
    {
        ll mn=INT_MAX;
        ll ind=-1;
        f(i,0,n,1)
        {
            if(a[i]<mn)
            {
                mn=a[i];
                ind=i;
            }
        }
        f(i,0,n,1)
        {
            if(a[i]>mn)
            {
                ll y=ceil((1.0*a[i])/mn);
                ans.pb({i,ind});
                a[i]=y;
            }
        }
        if(a==temp)
        {
            cout<<-1<<endl;
            return;
        }
        temp=a;
    }
    cout<<sz(ans)<<endl;
    f(i,0,sz(ans),1)
    {
        cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
    }

    
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