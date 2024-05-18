#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\29.divide-two-integers.cpp"
/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int l=0,r=dividend;
        int cnt=100;
        while(cnt--)
        {
            int mid=(l+r)/2;
            if(mid*divisor==dividend)
            {
                return mid;
            }
            else if(mid*divisor>dividend)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        return l;
    }
};
// @lc code=end

