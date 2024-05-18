#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\tsp_print.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int N = 4; // Change this to the number of cities in your problem.

vector<int> optimalPath;
int minCost = INF;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path, int curCity, int cost, int visitedCount)
{
    if (visitedCount == N)
    {
        if (graph[curCity][0] != 0 && cost + graph[curCity][0] <= minCost)
        {
            minCost = cost + graph[curCity][0];
            optimalPath = path;
        }
        return;
    }

    visited[curCity] = true;

    for (int nextCity = 0; nextCity < N; nextCity++)
    {
        if (!visited[nextCity] && graph[curCity][nextCity] != 0)
        {
            path.push_back(curCity);
            dfs(graph, visited, path, nextCity, cost + graph[curCity][nextCity], visitedCount + 1);
            path.pop_back();
        }
    }

    visited[curCity] = false;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 29, 20, 21},
        {29, 0, 15, 18},
        {20, 15, 0, 17},
        {21, 18, 17, 0}};

    vector<bool> visited(N+1, false);
    vector<int> path;

    dfs(graph, visited, path, 0, 0, 1);

    cout << "Optimal Tour Length: " << minCost << endl;
    cout << "Optimal Path: ";
    for (int city : optimalPath)
    {
        cout << city << " -> ";
    }
    cout << "0" << endl; // Return to the starting city.

    return 0;
}
