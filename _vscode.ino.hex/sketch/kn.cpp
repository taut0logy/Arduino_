#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\kn.cpp"
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to find all possible ways of selecting optimal solution in knapsack problem
void knapsackAll(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(capacity + 1));

    // Initialize the dp table
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w].push_back(0);
        }
    }

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                int withoutCurrent = dp[i - 1][w][0];
                int withCurrent = items[i - 1].value + dp[i - 1][w - items[i - 1].weight][0];

                if (withCurrent > withoutCurrent) {
                    dp[i][w] = dp[i - 1][w - items[i - 1].weight];
                    dp[i][w].push_back(i);
                } else if (withCurrent == withoutCurrent) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    dp[i][w] = dp[i - 1][w];
                    dp[i][w].push_back(i);
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print all possible solutions
    for (int i = 0; i < dp[n][capacity].size(); ++i) {
        int index = dp[n][capacity][i];
        if (index != 0) {
            cout << "Item " << index << ": Weight = " << items[index - 1].weight << ", Value = " << items[index - 1].value << endl;
        }
    }
}

int main() {
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "All possible ways to select optimal solution in knapsack:" << endl;
    knapsackAll(capacity, items);

    return 0;
}
