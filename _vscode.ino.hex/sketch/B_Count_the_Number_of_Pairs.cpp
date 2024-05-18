#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Count_the_Number_of_Pairs.cpp"
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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    mci m;
    f(i,0,n,1) m[s[i]]++;
    ll ans=0,cnt=0;
    /* for(auto x:m)
    {
        cout<<x.ff<<" "<<x.ss<<endl;
    } */
    f(i,0,n,1)
    {
        if((s[i]>='A' && s[i]<='Z') && m[s[i]] && m[s[i]+32])
        {
            cnt+=min(m[s[i]],m[s[i]+32]);
            ll x=min(m[s[i]],m[s[i]+32]);
            m[s[i]]-=x;
            m[s[i]+32]-=x;
        }
    }
    /* for(auto x:m)
    {
        cout<<x.ff<<" "<<x.ss<<endl;
    } */
    f(i,0,n,1)
    {
        if((s[i]>='A' && s[i]<='Z') && m[s[i]]>1 && !m[s[i]+32]) 
        {
            ans+=m[s[i]]/2;
            m[s[i]]=-1;
        }
        else if((s[i]>='a' && s[i]<='z') && m[s[i]]>1 && !m[s[i]-32]) 
        {
            ans+=m[s[i]]/2;
            m[s[i]]=-1;
        }
    }
    /* cout<<cnt<<" "<<ans<<endl;
    for(auto x:m)
    {
        cout<<x.ff<<" "<<x.ss<<endl;
    } */
    cnt+=min(ans,k);
    cout<<cnt<<endl;
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