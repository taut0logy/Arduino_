#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_The_Lakes.cpp"
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> vis;


int dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || !a[x][y] || vis[x][y])
        return 0;
    vis[x][y] = true;
    return a[x][y] + dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1);
}

class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

void solve()
{
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    DSU dsu(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                continue;

            for (const auto &dir : directions)
            {
                int x = i + dir.first;
                int y = j + dir.second;

                if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != 0)
                    dsu.unite(i * m + j, x * m + y);
            }
        }
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                continue;
            mp[dsu.find(i * m + j)] += a[i][j];
        }
    }

    int ans = 0;
    for (const auto &kvp : mp)
        ans = max(ans, kvp.second);

    cout << ans << endl;
    a.clear();
    vis.clear();
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
