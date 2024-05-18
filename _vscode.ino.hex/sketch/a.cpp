#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\a.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b,x) for(ll i=a;i<b;i+=x)
#define fr(i,a,b,x) for(ll i=a;i>=b;i-=x)
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
const ll mod=300000;
ll n;
ll a[mod];
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
ll lcm(ll a,ll b)
{
    ll x=a*b/gcd(a,b);
    return x;
}
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
bool isprime(long long n)
{
    long long l=sqrt(n);
    bool flag=true;
    if(n==2) flag=true;
    else if(n<2|| n%2==0)
    {
        flag=false;
    }
    else
    {
        for(int i=3;i<=l;i+=2)
        {
            if(n%i==0)
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
}
vector<ll> prime_factor(ll n)
{
    vector<ll>v;
    vector<ll>prime_fact;
    ll p[100000];
    for (ll i=0;i<100001;i++) p[i]=1;
    for (ll i=2;i<100001;i++)
    {
        if(p[i]==1)
        {
            for(ll j=2;i*j<100001;j++)
            {
                p[i*j]=0;
            }
        }
    }
    for (ll i=2;i<100001;i++)
    {
        if(p[i]==1) v.push_back(i);
    }
    for(ll i=0;i<v.size();i++)
    {
        while(n%v[i]==0)
        {
            prime_fact.push_back(v[i]);
            n/=v[i];
        }
    }
    return prime_fact;
}
void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFSUtil(int u, vector<int> adj[],vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
void dfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}
int hill(int i)
{
    if(i>0 && i<n-1 && a[i]>a[i-1] && a[i]>a[i+1]) return 1;
    return 0;
}
int valley(int i)
{
    if(i>0 && i<n-1 && a[i]<a[i-1] && a[i]<a[i+1]) return 1;
    return 0;
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
        cin>>n;
        int check[n]={0},cnt=0,ans=0;
        f(i,0,n,1) cin>>a[i];
        f(i,1,n-1,1) if(hill(i) || valley(i)) 
        {
            check[i]++;
            cnt++;
        }
        ans=cnt;
        f(i,1,n-1,1)
        {
            int temp=a[i];
            a[i]=a[i+1];
            int x;
            x=cnt-check[i]-check[i-1]-check[i+1]+hill(i-1)+valley(i-1)+hill(i)+valley(i)+hill(i+1)+valley(i+1);
            ans=min(x,ans);
            a[i]=a[i-1];
            x=cnt-check[i]-check[i-1]-check[i+1]+hill(i-1)+valley(i-1)+hill(i)+valley(i)+hill(i+1)+valley(i+1);
            ans=min(x,ans);
            a[i]=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}