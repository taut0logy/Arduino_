#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Moscow_Gorillas.cpp"
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
    ll p[n+1],q[n+1],posp[n+1],posq[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>p[i];
        posp[p[i]]=i;
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>q[i];
        posq[q[i]]=i;
    }
    ll l=min(posp[1],posq[1]),r=max(posp[1],posq[1]);
    ll ans=0;
    //MEX 1
    ans+=(l-1)*l/2; // 1 to l-1
    ans+=(n-r)*(n-r+1)/2;  // r+1 to n
    ans+=(r-l)*(r-l-1)/2; // l+1 to r-1
    //MEX 2 to n
    for(ll i=2;i<=n;i++)
    {
        ll L=posp[i],R=posq[i];
        if(L>R) swap(L,R);
        if((L<l || L>r) && (R<l || R>r)) // no overlap
        {
            if(L>r) ans+=(L-r)*l; // L>r>l
            else if(R<l) ans+=(l-R)*(n-r+1); // l>R>r
            else ans+=(R-r)*(l-L); // l>L>r
        }
        l=min(l,L);
        r=max(r,R);
    }
    cout<<ans+1<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
    
    return 0;
}