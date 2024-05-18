#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\611.valid-triangle-number.cpp"
/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution 
{
public:
    int bs(vector<int> &v,int l,int r,int x)
    {
        while(l<=r)
        {
            int m=(l+r)/2;
            if(v[m]>=x) r=m-1;
            else l=m+1;
        }
        return l;
    }
    int triangleNumber(vector<int>& nums)
    {
        int cnt=0;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return 0;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1 && nums[i];j++)
            {
                int x=bs(nums,i+2,nums.size()-1,nums[i]+nums[j])-1;
                if(x-j>0) cnt+=x-j;
            }
        }
        return cnt;
    }
};
// @lc code=end