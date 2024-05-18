#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Dijkstra.cpp"
#include <bits/stdc++.h>
using namespace std;



void dijkstra(vector<pair<int, int>> adj[], int n)
{
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWeight = it.second;
            if ((dis + adjWeight) < dist[adjNode])
            {
                dist[adjNode] = (dis + adjWeight);
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == INT_MAX)
        cout << -1;
    else
    {
        vector<int> ans;
        ans.push_back(n);
        int temp = n;
        while (parent[temp])
        {
            ans.push_back(parent[temp]);
            temp = parent[temp];
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(adj, n);
    return 0;
}
