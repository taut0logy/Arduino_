#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Letter.cpp"
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
    int n,m;
    cin>>n>>m;
    vs s;
    f(i,0,n,1)
    {
        string v;
        cin>>v;
        s.pb(v);
    }
    if(n==1)
    {
        int x1=m,x2=0;
        f(i,0,m,1) if(s[0][i]=='*') 
        {
            if(x1>i) x1=i;
            if(x2<i) x2=i;
        }
        f(i,x1,x2+1,1) cout<<s[0][i];
        cout<<endl;
    }
    else if(m==1)
    {
        int x1=n,x2=0;
        f(i,0,n,1) if(s[i][0]=='*') 
        {
            if(x1>i) x1=i;
            if(x2<i) x2=i;
        }
        f(i,x1,x2+1,1) cout<<s[i][0]<<endl;
    }
    else
    {
        int x1=n,x2=0;
        int y1=m,y2=0;
        f(i,0,n,1) 
        {
            f(j,0,m,1) 
            {
                if(s[i][j]=='*') 
                {
                    if(x1>i) x1=i;
                    if(x2<i) x2=i;
                    if(y1>j) y1=j;
                    if(y2<j) y2=j;
                }
            }
        }
        //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' '<<endl;
        f(i,x1,x2+1,1)
        {
            f(j,y1,y2+1,1)
            {
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    int test=t;
    while(t--)
    {
        solve();
    }
    return 0;
}