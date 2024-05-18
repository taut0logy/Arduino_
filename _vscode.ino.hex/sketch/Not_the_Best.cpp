#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Not_the_Best.cpp"
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
int second_shortest_path(vector<pii> adj[],int n,int src,int dst)
{
    vector<int>dist(n+1,INT_MAX);
    vector<int>dist2(n+1,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        int node_dist=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            int next_node=it.first;
            int next_node_dist=it.second;
            if(dist[next_node]>node_dist+next_node_dist)
            {
                dist2[next_node]=dist[next_node];
                dist[next_node]=node_dist+next_node_dist;
                pq.push({dist[next_node],next_node});
            }
            else if(dist2[next_node]>node_dist+next_node_dist && dist[next_node]!=node_dist+next_node_dist)
            {
                dist2[next_node]=node_dist+next_node_dist;
                pq.push({dist2[next_node],next_node});
            }
        }
    }
    return dist2[dst];
}

int prims(vector<pii> adj[],int n,int src)
{
    vector<bool>vis(n+1,false);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int> mst[n+1];
    pq.push({0,src});
    int cost=0;
    int cnt=0;
    while(!pq.empty() && cnt!=n)
    {
        int node=pq.top().second;
        int node_dist=pq.top().first;
        pq.pop();
        if(vis[node])
        {
            continue;
        }
        cost+=node_dist;
        vis[node]=true;
        cnt++;
        for(auto it:adj[node])
        {
            int next_node=it.first;
            int next_node_dist=it.second;
            if(!vis[next_node])
            {
                pq.push({next_node_dist,next_node});
            }
        }
    }
    return cost;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int ans=second_shortest_path(adj,n,1,n);
    cout<<ans<<endl;
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
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}