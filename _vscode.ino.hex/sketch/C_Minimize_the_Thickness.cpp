#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Minimize_the_Thickness.cpp"
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
ll gcd(ll a, ll b)
{
    ll x=min(a,b);
    while(x>0)
    {
        if(a%x==0 && b%x==0) break;
        x--;
    }
    return x;
}
vi div(ll n)
{
    vi v;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        { 
            v.pb(i);
            if(n/i!=i) v.pb(n/i);
        }
    }
    return v;
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
        int n;
        cin>>n;
        int ans=n;
        ll a[n],sum=0,mn=INT_MAX,mx=INT_MIN;
        f(i,0,n,1) 
        {
            cin>>a[i];
            sum+=a[i];
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        if(mn==mx)
        {
            cout<<1<<endl;
            continue;
        }
        vi vv=div(sum);
        //printv(vv);
        if(vv.size()<=2) cout<<n<<endl;
        else
        {
            ff(x,vv)
            {
                ll res=sum/x,seg=0;
                int s=0,m=0,th=0;
                bool f=true;
                f(i,0,n,1)
                {
                    seg+=a[i];
                    th++;
                    if(seg==res)
                    {
                        m=max(m,th);
                        th=0;
                        seg=0;
                    }
                    else if(seg>res)
                    {
                        f=false;
                        break;
                    }
                }
                if(f) ans=min(ans,m);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}