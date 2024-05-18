#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab_03_b2.cpp"
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

int n, m, src;
vector<edge> edges;
vector<int> parent;

void bellman_ford(vector<edge> &edges, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<int> updated; // Keep track of updated vertices
    for (int i = 0; i < n; i++)
    {
        updated.clear();
        for (auto e : edges)
        {
            if (dist[e.u] < INT_MAX)
            {
                if (dist[e.v] > dist[e.u] + e.w)
                {
                    dist[e.v] = dist[e.u] + e.w;
                    parent[e.v] = e.u;
                    updated.push_back(e.v); // Track updated vertices
                }
            }
        }
    }

    // Check if negative cycle exists
    if (!updated.empty())
    {
        cout << "Negative cycle(s) found:" << endl;
        for (int x : updated)
        {
            int y = x;
            for (int i = 0; i < n; i++)
                y = parent[y];
            vector<int> cycle;
            for (int cur = y;; cur = parent[cur])
            {
                cycle.push_back(cur);
                if (cur == y && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());
            for (auto e : cycle)
                cout << e << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No negative cycle found" << endl;
    }
}

int main()
{
    cin >> n >> m;
    parent.assign(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
    cin >> src;
    bellman_ford(edges, src);
    return 0;
}
