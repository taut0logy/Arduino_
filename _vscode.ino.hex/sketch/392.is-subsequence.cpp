#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\392.is-subsequence.cpp"
/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char> st;
        for(int i=s.size()-1;i>=0;i--)
        {
            st.push(s[i]);
        }
        for(int i=0;i<t.size();i++)
        {
            if(!st.empty() && st.top()==t[i])
            {
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

