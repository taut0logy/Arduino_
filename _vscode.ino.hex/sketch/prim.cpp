#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\prim.cpp"
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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


int main()
{
    int n,m;
    cin>>n>>m;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int ans=prims(adj,n,1);
    cout<<ans<<endl;
    return 0;
}