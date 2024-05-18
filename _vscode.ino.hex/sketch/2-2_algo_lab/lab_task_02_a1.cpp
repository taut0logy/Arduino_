#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\2-2_algo_lab\\lab_task_02_a1.cpp"
#include<bits/stdc++.h>
using namespace std;
map<string,int> djigstra(map<string,vector<pair<string,int>>> adj,string src,map<string,string> &path)
{
    map<string,int> dist;
    for(auto e:adj)
    {
        dist[e.first]=INT_MAX;
        path[e.first]="";
    }
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
    q.push({0,src});
    dist[src]=0;
    while(!q.empty())
    {
        int d=q.top().first;
        string u=q.top().second;
        q.pop();
        if(dist[u]<d) continue;
        for(auto e:adj[u])
        {
            string v=e.first;
            int w=e.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                path[v]=u;
                q.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main()
{
    cout<<"Enter number of cities and number of roads"<<endl;
    int n,m;
    cin>>n>>m;
    map<string,vector<pair<string,int>>> adj;
    cout<<"Enter city1 city2 distance"<<endl;
    for(int i=0;i<m;i++)
    {
        string u,v;
        int w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    string src,dst;
    cout<<"Enter source and destination"<<endl;
    cin>>src>>dst;
    map<string,string> path;
    map<string,int> dist=djigstra(adj,src,path);
    if(dist[dst]==INT_MAX)
    {
        cout<<"No path found"<<"from "<<src<<" to "<<dst<<endl;
        return 0;
    }
    string cur=dst;
    stack<string> st;
    cout<<"Shortest distance from "<<src<<" to "<<dst<<" is "<<dist[dst]<<endl;
    cout<<"Shortest path from "<<src<<" to "<<dst<<" is :"<<endl;
    while(cur!="")
    {
        st.push(cur);
        cur=path[cur];
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
        if(!st.empty())
            cout<<"->";
    }
    cout<<endl;
}