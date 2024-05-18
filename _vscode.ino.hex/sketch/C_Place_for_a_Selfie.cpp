#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Place_for_a_Selfie.cpp"
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
#define double long double
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
bool compare(double a, double b)
{
    double eps = 1e-9;
    return a + eps < b;
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<double> k(n);
    f(i,0,n,1)
    {
        cin>>k[i];
    }
    sort(all(k));
    for(int i=0;i<m;i++)
    {
        /* if(upper_bound(k.bg,k.en,slope[i])!=k.en)
        {
            ll ans=*upper_bound(k.bg,k.en,slope[i]);
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else
        {
           cout<<"NO"<<endl; 
        } */
        ll a,b,c;
        cin>>a>>b>>c;
        double y=1.0*b-2*sqrt(1.0*a*c);
        double z=1.0*b+2*sqrt(1.0*a*c);
        if(upper_bound(k.bg,k.en,y,compare)!=k.en )
        {
            ll ans=*upper_bound(k.bg,k.en,y,compare);
            int ind=upper_bound(k.bg,k.en,y,compare)-k.bg;
            if(ans>=z)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
                cout<<ans<<endl;
            }
        }
        else
        {
           cout<<"NO"<<endl; 
        }
    }
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