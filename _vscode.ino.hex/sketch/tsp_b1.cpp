#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\tsp_b1.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int tspWithBlockedCities(const std::vector<std::vector<int>>& graph, int mask, int pos, std::vector<std::vector<int>>& dp, const std::vector<int>& blockedCities) {
    int n = graph.size();
    
    // If all cities have been visited
    if (mask == (1 << n) - 1) {
        return graph[pos][0]; // Return to the starting city (0)
    }
    
    // If the subproblem has already been solved
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    
    int minCost = INF;
    
    // Try visiting unvisited and unblocked cities
    for (int nextCity = 0; nextCity < n; ++nextCity) {
        if ((mask & (1 << nextCity)) == 0 && !blockedCities[nextCity]) { // Check if the city is unvisited and not blocked
            int newMask = mask | (1 << nextCity);
            int cost = graph[pos][nextCity] + tspWithBlockedCities(graph, newMask, nextCity, dp, blockedCities);
            minCost = std::min(minCost, cost);
        }
    }
    
    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };
    
    int n = graph.size();
    
    // Initialize memoization table with -1
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, -1));
    
    // Start from the first city (0)
    int mask = 1;
    int startCity = 0;

    // Define blocked cities, where 1 indicates blocked and 0 indicates unblocked
    std::vector<int> blockedCities(n, 0);
    // For example, let's block city 2
    blockedCities[2] = 1;

    int shortestDistance = tspWithBlockedCities(graph, mask, startCity, dp, blockedCities);
    
    std::cout << "Shortest Distance: " << shortestDistance << std::endl;
    
    return 0;
}