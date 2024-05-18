#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Powers_Of_Two.cpp"
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
    ll n,k,i=0,set=0,l=0;
    cin>>n>>k;
    stack<ll> s;
    mll m;
    if(k==1)
    {
        if(log2(n)==(int)log2(n))
        {
            cout<<"YES"<<endl<<n<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return;
    }
    while(n)
    {
        if(n%2)
        {
            set++;
            ll y=pow(2,i);
            if(y>1)s.push(y);
            m[y]++;
        }
        i++;
        n/=2;
        l++;
    }
    if(set>k)
    {
        cout<<"NO"<<endl;
        return;
    }
    while(set<k && !s.empty())
    {
        ll x=s.top();
        s.pop();
        m[x]--;
        m[x/2]+=2;
        if(x/2>1)
        {
            s.push(x/2);
            s.push(x/2);
        }
        set++;
    }
    if(set<k)
    {
        cout<<"NO"<<endl;
        return;
    }
    //cout<<set<<endl;
    cout<<"YES"<<endl;
    for(auto it:m)
    {
        while(it.ss--)
        {
            cout<<it.ff<<" ";
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
    //cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}