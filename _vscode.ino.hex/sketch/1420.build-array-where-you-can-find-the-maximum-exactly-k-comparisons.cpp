#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\1420.build-array-where-you-can-find-the-maximum-exactly-k-comparisons.cpp"
/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        for (int j = 1; j <= m; ++j) {
            dp[1][j][1] = 1; //because we have to find the maximum element
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int l = 1; l <= k; ++l) {
                    dp[i][j][l] = (dp[i][j][l] + (long)j * dp[i - 1][j][l]) % 1000000007;  //case 1: the last element is the maximum of the array
                    for (int p = 1; p < j; ++p) {
                        dp[i][j][l] = (dp[i][j][l] + dp[i - 1][p][l - 1]) % 1000000007;  //case 2: the last element is not the maximum of the array
                    }
                }
            }
        }
        int res = 0;
        for (int j = 1; j <= m; ++j) {
            res = (res + dp[n][j][k]) % 1000000007;
        }
        return res;
    }
};
// @lc code=end

