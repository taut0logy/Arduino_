#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\djigstra.cpp"
#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>>adj,int n,int src)
{
    vector<int> ans;
    vector<int>vis(n,0);
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
void topological_sort(vector<vector<int>>adj)
{
    int n=adj.size();
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    for(auto it:topo)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
// topological sort using dfs
void dfs(int node,vector<int>&vis,vector<int>&stack,vector<vector<int>>adj)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,stack,adj);
        }
    }
    stack.push_back(node);
}
vector<int> topological_sort(vector<vector<int>>adj,int n)
{
    vector<int>vis(n,0);
    vector<int>stack;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,stack,adj);
        }
    }
    reverse(stack.begin(),stack.end());
    return stack;
}
vector<int> djigstra(vector<vector<pair<int,int>>>adj,int n,int src,vector<int>&par)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    par.assign(n,-1); // to store the parent of each node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src}); // {distance,node}
    while(!pq.empty())
    {
        int node=pq.top().second;
        int node_dist=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            if(node_dist+it.second<dist[it.first])
            {
                dist[it.first]=node_dist+it.second;
                par[it.first]=node;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist; // return the distance of each node from source
}
//use djigstra's algorithm to get maximu probabibity o reaching a node from source
vector<double> djigstra(vector<vector<pair<int,double>>>adj,int n,int src)
{
    vector<double>dist(n,0);
    dist[src]=1;
    int par[n];
    priority_queue<pair<double,int>>pq;
    pq.push({1,src});
    while(!pq.empty())
    {
        int node=pq.top().second;
        double node_dist=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            if(node_dist*it.second>dist[it.first])
            {
                par[it.first]=node;
                dist[it.first]=node_dist*it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist;
}
//implement djigstra's algorithm without using priority queue
vector<int> djigstra2(vector<vector<pair<int,int>>>adj,int n,int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    vector<bool>vis(n,false);
    for(int i=0;i<n-1;i++)
    {
        int mn=INT_MAX;
        int u=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j] && dist[j]<mn)
            {
                mn=dist[j];
                u=j;
            }
        }
        vis[u]=true;
        for(auto it:adj[u])
        {
            if(dist[u]+it.second<dist[it.first])
            {
                dist[it.first]=dist[u]+it.second;
            }
        }
    }
    return dist;
}
// shortest path using bfs
int shortest_path(vector<vector<int>>adj,int n,int src,int dest)
{
    vector<int>dist(n,INT_MAX);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    return dist[dest];
}
void dfs(int node,vector<int>&vis,vector<vector<int>>adj)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj);
        }
    }
}
int no_of_components(vector<vector<int>>adj,int n)
{
    vector<int>vis(n,0);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i,vis,adj);
        }
    }
    return count;
}
// cycle detection in directed graph
bool cycle_detection(int node,vector<int>&vis,vector<int>&stack,vector<vector<int>>adj)
{
    vis[node]=1;
    stack[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(cycle_detection(it,vis,stack,adj))
            {
                return true;
            }
        }
        else if(stack[it])
        {
            return true;
        }
    }
    stack[node]=0;
    return false;
}
vector<int> bellman_ford(vector<vector<int>>edges,int n,int src)    
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
        {
            cout<<"Negative cycle"<<endl;
            exit(0);
        }
    }
    return dist;
}
vector<int> bellman_ford(vector<vector<pair<int,int>>>adj,int n,int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(auto it:adj[j])
            {
                if(dist[j]!=INT_MAX && dist[j]+it.second<dist[it.first])
                {
                    dist[it.first]=dist[j]+it.second;
                }
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        for(auto it:adj[j])
        {
            if(dist[j]!=INT_MAX && dist[j]+it.second<dist[it.first])
            {
                cout<<"Negative cycle"<<endl;
                exit(0);
            }
        }
    }
    return dist;
}

// floyd warshall algorithm
vector<vector<int>> floyd_warshall(vector<vector<pair<int,int>>> adj,int n)
{
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            dist[i][it.first]=it.second;
        }
    }
    for(int i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;
}

// floyd warshall algorithm for adjacency matrix
vector<vector<int>> floyd_warshall(vector<vector<int>> adjmatrix)
{
    vector<vector<int>>dist=adjmatrix;
    int n=adjmatrix.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<pair<int,int>>>adj;
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int>par;
    vector<int>dist=djigstra(adj,n,0,par);
    for(auto it:dist)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;

}