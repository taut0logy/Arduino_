#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\1.two-sum.cpp"
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i])!=0)
            {
                return {m[target-nums[i]], i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

