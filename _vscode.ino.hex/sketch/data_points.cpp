#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\data_points.cpp"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> adjlist(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adjlist[a].push_back({b, c});
            adjlist[b].push_back({a, c});
        }
        int mx = 1e8;
        vector<bool> vis(n + 1, false);
        vector<int> dist(n + 1, mx);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (auto to : adjlist[u])
            {
                int v = to.first, w = to.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        cout<<"Case #"<<i<<": ";
        if (dist[t] == mx)
        {
            cout << "unreachable" << '\n';
        }
        else
        {
            cout << dist[t] << '\n';
        }
        //cout << '\n';
    }
}
