#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\27a.cpp"
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
int bs(ll a[],int l,int r,ll x)
{
    while(r>=l)
    {
        ll m=(l+r)/2;
        if (a[m] >= x) r=m-1;
        else l=m+1;
    }
    return l;
}
int bs2(ll v[], int l, int r, ll x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] == x) return m;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
void printv(vector<auto> v)
{
    for(auto x: v) cout<<x<<' ';
    cout<<endl;
}
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
ll mod=100000007;
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
        int n;
        cin>>n;
        ll a[n];
        vector<pair<ll,string>> m;
        vs v;
        f(i,0,n,1) 
        {
            string s,ss;
            cin>>s;
            //ss=s;
            //reverse(s.bg,s.en);
            ll x=0;
            f(i,0,s.size(),1)
            {
                ll m=(s[i]-'0')*pow(10,s.size()-1-i);
                x+=(m%mod);
            }
            a[i]=x;
            m.pb({x,s});
        }
        sort(a,a+n);
        vsort(m);
        ff(x,m) v.pb(x.second);
        bool f=true;
        for(int i=0;i<n && f;i++)
        {
            for(int j=i+1;j<n-1 && f;j++)
            {
                if(a[i]+a[j]>a[j+1])
                {
                    //printf("%lld %lld %lld",a[i],a[j],a[j+1]);
                    cout<<v[i]<<' '<<v[j]<<' '<<v[j+1];
                    f=false;
                }
            }
        }
        if(f) printf("0 0 0");
        cout<<endl;
        f(i,0,n,1)cout<<a[i]<<' ';
    }
    return 0;
}