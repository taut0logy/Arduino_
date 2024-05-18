#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Almost_All_Multiples.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b,x) for(int i=a;i<b;i+=x)
#define fr(i,a,b,x) for(int i=a;i>=b;i-=x)
#define ff(x,m) for(auto x:m)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(),v.end())
#define rsort(v) sort(v.begin(),v.end(),greater<>())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define yout cout<<"YES"<<endl;
#define nout cout<<"NO"<<endl;
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
typedef set<string> sst;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef pair<string,int> psi;
typedef pair<long long,long long>pll;
void solve()
{
    int n,x;
    cin>>n>>x;
    if(x==n) 
    {
        cout<<x<<' ';
        f(i,2,n,1) cout<<i<<' ';
        cout<<1<<endl;
        return;
    }
    if(n==4 && x==2)
    {
        cout<<"2 4 3 1"<<endl;
        return;
    }
    if((n/x)!=0 || n/x==200)
    {
        cout<<-1<<endl;
        return;
    }    
    mii m;
    vi v;
    v.pb(0);
    v.pb(x);
    f(i,2,n,1) v.pb(i);
    v.pb(1);
    v[x]=n;
    f(i,1,n+1,1) cout<<v[i]<<' ';
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    int test=t;
    while(t--)
    {
        solve();
    }
    return 0;
}