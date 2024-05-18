#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Farthest_Nodes_in_a_Tree.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<vector<pair<int,int>>> &adj, vector<int> &dist, int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : adj[u])
        {
            if (dist[v.first] == -1)
            {
                dist[v.first] = dist[u] + v.second;
                q.push(v.first);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n + 1, -1);
    bfs(adj, dist, 0);
    int mx = -1, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
            idx = i;
        }
    }
    dist.assign(n + 1, -1);
    bfs(adj, dist, idx);
    mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
        }
    }
    cout << mx << endl;
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