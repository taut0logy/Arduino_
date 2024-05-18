#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\01knapsack.cpp"
#include <bits/stdc++.h>
using namespace std;

vector<bool> knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    vector<bool> isTaken(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[i - 1] <= w)
            {
                include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
            }
            int exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }

    int i = n;
    int w = maxWeight;
    while (i > 0 && w > 0)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            isTaken[i]=true;
            w -= weight[i - 1];
        }
        i--;
    }
    return isTaken;
}

bool canhave(vector<int> weight, vector<int> value, int n, int target)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int p = 1; p <= target; p++)
        {
            if(value[i - 1] > p)
            {
                dp[i][p] = dp[i - 1][p];
            }
            else
            {
                dp[i][p] = dp[i - 1][p] || dp[i - 1][p - value[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    int n;
    int maxWeight;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> maxWeight;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int targetProfit;
    cout << "Enter the target profit to achieve: ";
    cin >> targetProfit;

    bool result = canhave(weight, value, n, targetProfit);

    if (result)
    {
        cout << "It is possible to achieve the target profit with the given items and weights." << endl;
    }
    else
    {
        cout << "It is not possible to achieve the target profit with the given items and weights." << endl;
    }

    return 0;
}






/* int main()
{
    int n;
    int maxWeight;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> maxWeight;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int result = knapsack(weight, value, n, maxWeight);

    cout << "The maximum value that can be obtained is: " << result << endl;

    return 0;
}
 */