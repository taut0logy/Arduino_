#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Maximum_Set.cpp"
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
const long long M=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vl>v(1e6+1,{1});
    vector<mll>m(1e6+1);
    f(i,1,1001,1)
    {
        ll ind=1;
        ll x=i;
        if(x%2==0)
        {
            v[i].pb(2);
            m[i][2]=ind;
            ind++;
        }
        for(ll j=3;j*j<=x;j+=2)
        {
            if(x%j==0)
            {
                v[i].pb(j);
                m[i][j]=ind;
                ind++;
                if(j*j!=x)
                {
                    v[i].pb(x/j);
                    m[i][x/j]=ind;
                    ind++;
                }
            }
        }
    }
    //cout<<"done"<<endl;
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=0,cnt=0;
        f(i,1,1e6+1,1)
        {
            if(m[i][l] && m[i][r] && v[i].size()==2)
            {
                ans++;
                /* ll x=lb(all(v[i]),l)-v[i].bg;
                ll y=lb(all(v[i]),r)-v[i].bg; */
                ll len=m[i][r]-m[i][l]+1;
                cnt=(cnt+(len*(len+1))/2)%M;
            }
        }
        cout<<ans<<" "<<cnt<<endl;
    }
    return 0;
}