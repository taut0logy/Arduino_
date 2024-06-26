#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\31.next-permutation.cpp"
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0)
        {
            int j=n-1;
            while(j>=0 && nums[j]<=nums[i]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
// @lc code=end

