#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\238.product-of-array-except-self.cpp"
/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int n=1,z=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]) n*=nums[i];
            else z++;
        }
        if(z==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                v.push_back(n/nums[i]);
            }
            return v;
        }
        if(z>1)
        {
            for(int i=0;i<nums.size();i++)
            {
                v.push_back(0);
            }
            return v;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i]) v.push_back(n);
            else v.push_back(0);
        }
        return v;
    }
};
// @lc code=end

