#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Country_Roads.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int src;
    cin>>src;
    vector<int> dist(v,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {   
            int v=it.first;
            int d=max(dist[node],it.second);
            if(dist[v]>d)
            {
                dist[v]=d;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        if(dist[i]==INT_MAX)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            cout<<dist[i]<<endl;
        }
    }
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
        cout<<"Case "<<TT<<":\n";
        solve();
    }
    return 0;
}