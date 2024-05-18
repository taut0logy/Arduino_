#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Copil_Copac_Draws_Trees.cpp"
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
int cnt=1;
void dfs(vector<vector<pii>> &adj,int u,int p,int step,int last)
{
    cnt=max(cnt,step);
    for(auto x:adj[u])
    {
        if(x.ff==p)
            continue;
        int s=step;
        if(x.ss<last) s++;
        dfs(adj,x.ff,u,s,x.ss);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<pii>> adj(n+1);
    cnt=1;
    for(int i=0;i<n-1;i++)
    {
        
        int u,v;
        cin>>u>>v;
        adj[u].pb({v,i+1});
        adj[v].pb({u,i+1});
    }
    dfs(adj,1,0,1,0);
    cout<<cnt<<endl;
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