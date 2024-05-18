#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\task_dp_a1.cpp"
//find the minimum number of coins required to make a value 'val'
//given that you have a limited number of each type of coin
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, val;
vector<int> coins(1005); //coin values
int ccount[1005]; //max number of each coin
int cval[1005]; //to keep track of number of each coin used
int dp[1005][1005]; //memoization table

int count(int i, int v)
{
    if (v == 0) return 0;
    if (i <= 0 || v < 0) return INF;
    if (dp[i][v] != -1) return dp[i][v];

    int exclude = count(i - 1, v);
    int include = INF;

    if (cval[i - 1] < ccount[i - 1] && v >= coins[i - 1])
    {
        include = 1 + count(i, v - coins[i - 1]);
        cval[i - 1]++;
    }

    return dp[i][v] = min(include, exclude);
}

int main()
{
    cin >> n >> val;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 0; i < n; i++) cin >> ccount[i];

    memset(dp, -1, sizeof(dp));
    memset(cval, 0, sizeof(cval));

    int ans = count(n, val);

    if (ans == INF) cout << "-1";
    else cout << ans;

    return 0;
}