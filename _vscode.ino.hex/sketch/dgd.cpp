#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dgd.cpp"
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        currentMinimum = nums[0]
        currentMaximum = nums[0]
        globalMaximum = nums[0]

        start = 0
        end = 1

        for i in range(1,len(nums)):
            currentMinimum, currentMaximum  = min(currentMinimum * nums[i], currentMaximum * nums[i], nums[i]), max(currentMinimum * nums[i], currentMaximum * nums[i], nums[i])
            
            if (currentMaximum > globalMaximum):
                globalMaximum = currentMaximum
                end=i+1
                

        j=end-1
        while j>=0:
            if nums[j]==0:
                start = j
                break
            else:
                if globalMaximum == nums[j]:
                    start = j
                    break
                globalMaximum = globalMaximum/nums[j]
            j-=1

        #nums[start: end] is the maximum product subarray!!
        prod = 1
        for num in nums[start: end]:
            prod *=num

        return prod