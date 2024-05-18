#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\djigstra_opi_sir.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> dijkstra(int s, int t, int n, vector<vector<pair<int, long long>>>& g) {
    const long long inf = 1e18;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    q.push({0, s});
    d[s] = 0;
    while (!q.empty()) {
        auto x = q.top();
        q.pop();
        int u = x.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto y : g[u]) {
            int v = y.first;
            long long w = y.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m; // n is the number of nodes, m is the number of edges
    vector<vector<pair<int, long long>>> g(n + 1); // adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w; // edge from u to v with weight w
        g[u].emplace_back(v, w);
    }
    int start_node, end_node;
    cin >> start_node >> end_node; // source and target nodes

    vector<long long> distances = dijkstra(start_node, end_node, n, g);

    if (distances[end_node] == 1e18) {
        cout << "No path from " << start_node << " to " << end_node << "\n";
    } else {
        cout << "Shortest distance from " << start_node << " to " << end_node << ": " << distances[end_node] << "\n";
    }

    return 0;
}
