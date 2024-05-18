#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\pr2.cpp"
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
    vector<vl> prefpiece,suffpiece;
    for(auto x:pieces)
    {
        vl v;
        ll sum=0;
        for(auto y:x)
        {
            sum+=y;
            v.pb(sum);
        }
        prefpiece.pb(v);
    }
    //for(auto x:prefpiece) {for(auto y:x) cout<<y<<' ';cout<<endl;}
    //cout<<endl;
    for(auto x:pieces)
    {
        vl v;
        ll sum=0;
        for(int i=x.size()-1;i>=0;i--)
        {
            sum+=x[i];
            v.pb(sum);
        }
        //reverse(all(v));
        suffpiece.pb(v);
    }
    //for(auto x:suffpiece) {for(auto y:x) cout<<y<<' ';cout<<endl;}
    //cout<<endl;
    int mxlen=0;
    for(int i=0;i<pieces.size();i++)
    {

        int mx=lower_bound(all(prefpiece[i]),k)-prefpiece[i].bg;
        int mx2=lower_bound(all(suffpiece[i]),k)-suffpiece[i].bg;
        
        //cout<<mx<<' '<<mx2<<endl;
        mxlen=max(mxlen,mx);
        mxlen=max(mxlen,mx2);
        int l=0,r=mx-1,sum=prefpiece[i][mx-1];
        //cout<<l<<' '<<r<<' '<<sum<<endl;
        while(r<pieces[i].size())
        {
            //cout<<'l'<<endl;
            l++;
            sum-=pieces[i][l];
            while(r<pieces[i].size() && sum<=k)
            {
                sum+=pieces[i][r];
                r++;
            }
            mxlen=max(mxlen,r-l+1);
        }
        l=mx2-1,r=pieces[i].size()-1,sum=suffpiece[i][mx2-1];
        reverse(all(suffpiece[i]));
        //for(auto x:suffpiece[i]) cout<<x<<' ';cout<<endl;
        //cout<<sum<<endl;
        //cout<<l<<' '<<r<<' '<<sum<<endl;
        while(l>=0)
        {
            //cout<<'r'<<endl;
            r--;
            sum-=pieces[i][r];
            while(l>=0 && sum<=k)
            {
                sum+=pieces[i][l];
                l--;
            }
            mxlen=max(mxlen,r-l+1);
        }
        //cout<<endl;
    }
    //if(mxlen) mxlen--;
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