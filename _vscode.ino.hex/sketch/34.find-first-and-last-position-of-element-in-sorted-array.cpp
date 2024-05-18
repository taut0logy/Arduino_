#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\34.find-first-and-last-position-of-element-in-sorted-array.cpp"
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(start==nums.size()||nums[start]!=target) return {-1,-1};
        else return {start,end-1};
        
    }
};
// @lc code=end

