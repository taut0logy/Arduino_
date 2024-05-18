#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Back_to_Underworld.cpp"
#include <bits/stdc++.h>
using namespace std;
int vis[20005]={0};
int bfs(int s,vector<vector<int>>&adj)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    int cnt1=1,cnt2=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                if(vis[u]==1)
                {
                    vis[v]=2;
                    cnt2++;
                }
                else
                {
                    vis[v]=1;
                    cnt1++;
                }
                q.push(v);
            }
        }
    }
    return max(cnt1,cnt2);
}
void solve()
{
    memset(vis,false,sizeof(vis));
    int n;
    cin>>n;
    vector<vector<int>>adj(20005);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx=0;
    for(int i=0;i<20005;i++)
    {
        if(!vis[i] && !adj[i].empty())
        {
            mx+=bfs(i,adj);
        }
    }
    cout<<mx<<endl;
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