#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_Money_Trees.cpp"
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

int ff(vl &v,ll k)
{
    int n=v.size();
    ll prefixSum[n];
    prefixSum[0]=v[0];
    for(int i=1;i<n;i++)
    {
        prefixSum[i]=prefixSum[i-1]+v[i];
    }
    int ans=0,i=0,j=0;
    while(j<n)
    {
        ll sum;
        if(i==0) sum=prefixSum[j];
        else sum=prefixSum[j]-prefixSum[i-1];
        if(sum<=k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else i++;
    }
    return ans;
}

void solve()
{
    ll k,n;
    cin>>n>>k;
    ll a[n],h[n];
    vector<pll>ind;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int i=0,j=0;
    vector<vl> pieces;
    for(int pos=0;pos<n;pos++)
    {
        vl v;
        v.pb(a[pos]);
        i=pos,j=pos;
        while(j<n-1 && h[j]%h[j+1]==0)
        {
            v.pb(a[j+1]);
            j++;
        }
        ind.emplace_back(i,j);
        pieces.pb(v);
        pos=j;
    }
    //for(auto x:pieces) {for(auto y:x) cout<<y<<' ';cout<<endl;}
    //cout<<endl;


    int mxlen=0;
    for(auto x:pieces)
    {
        int len=ff(x,k);
        mxlen=max(mxlen,len);
    }

    cout<<mxlen<<endl;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    for(TT=1;TT<=Test;TT++)
    {
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}