#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\15.3-sum.cpp"
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vector<int> v1;
                    v1.push_back(nums[i]);
                    v1.push_back(nums[l]);
                    v1.push_back(nums[r]);
                    v.push_back(v1);
                    l++;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if(nums[i]+nums[l]+nums[r]<0)
                    l++;
                else
                    r--;
            }
        }
        return v;
    }
};
// @lc code=end

