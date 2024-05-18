#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_Lazy_KUETian.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll inf=1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<pll> adj[n+5],rev[n+5];
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        rev[v].push_back({u,2*w});
    }
    vector<vector<ll>> dist(n+5,vector<ll>(k+5,inf));
    vector<vector<bool>> vis(n+5,vector<bool>(k+5,false));
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
    pq.push({0,{s,k}});
    dist[s][k]=0;
    while(!pq.empty())
    {
        ll u=pq.top().second.first;
        ll d=pq.top().first;
        ll cnt=pq.top().second.second;
        pq.pop();
        if(vis[u][cnt])
            continue;
        vis[u][cnt]=true;
        if(d>dist[u][cnt])
            continue;
        for(auto i:adj[u])
        {
            ll v=i.first;
            ll w=i.second;
            if(vis[v][cnt])
                continue;
            if(dist[v][cnt]>dist[u][cnt]+w)
            {
                dist[v][cnt]=dist[u][cnt]+w;
                pq.push({dist[v][cnt],{v,cnt}});
            }
        }
        if(cnt>0)
        {
            for(auto i:rev[u])
            {
                ll v=i.first;
                ll w=i.second;
                if(vis[v][cnt-1])
                    continue;
                if(dist[v][cnt-1]>dist[u][cnt]+w)
                {
                    dist[v][cnt-1]=dist[u][cnt]+w;
                    pq.push({dist[v][cnt-1],{v,cnt-1}});
                }
            }
        }
    }
    vector<ll> ans(n+1,inf);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            ans[i]=min(ans[i],dist[i][j]);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(ans[x]==inf)
            cout<<-1<<endl;
        else
            cout<<ans[x]<<endl;
    }
    return 0;
}