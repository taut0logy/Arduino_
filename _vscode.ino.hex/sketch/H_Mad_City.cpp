#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\H_Mad_City.cpp"
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
vector<int> adj[200005];
bool vis[200005]={0};
int n;
int dfsen(int node,int par)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(child==par) continue;
        if(vis[child])  return child;
        else
        {
            int temp=dfsen(child,node);
            if(temp!=-1)
            {
                return temp;
            }
        }
    }
    return -1;
}

int dfsmindist(int x,int entry)
{
    if(x==entry) return 0;
    vis[x]=1;
    int mn=n;
    for(auto i:adj[x])
    {
        if(i==entry)  return 1;
        if(!vis[i])
        {
            mn=min(mn,dfsmindist(i,entry)+1);
        }
    }
    return mn;
}
void solve()
{
    int a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(a==b)
    {
        yn(0);
        return;
    }
    memset(vis,0,sizeof(vis));
    int entry=dfsen(b,-1);

    memset(vis,0,sizeof(vis));
    int dista=dfsmindist(a,entry);

    memset(vis,0,sizeof(vis));
    int distb=dfsmindist(b,entry);

    //cout<<dista<<" "<<distb<<" ";
    yn(distb<dista);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}