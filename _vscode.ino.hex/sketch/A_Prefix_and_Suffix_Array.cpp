#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Prefix_and_Suffix_Array.cpp"
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
    ll n;
    cin>>n;
    msi m;
    msi len;
    f(i,0,2*(n-1),1)
    {
        string s;
        cin>>s;
        m[s]++;
        len[s]=sz(s);
    }
    /* for(auto x:m)
    cout<<x.ff<<" "<<x.ss<<endl;
    for(auto x:len)
    cout<<x.ff<<" "<<x.ss<<endl; */
/*     if(n==3)
    {
        for(auto x:m)
        {
            if(x.ss==2)
            {
                //cout<<x.ff<<endl;
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
        return;
    } */
    for(auto x:m)
    {
        string s2=x.ff;
        reverse(all(s2));
        if(x.ff==s2)
        {
            if(m[s2]==2 && len[x.ff]==n/2)
            {
                //cout<<x.ff<<endl;
                cout<<"YES"<<endl;
                return;
            }
        }
        else if(m[s2] && len[x.ff]==floor(n/2))
        {
            //cout<<x.ff<<endl;
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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