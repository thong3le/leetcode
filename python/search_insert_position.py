class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums or nums[0] > target:
            return 0
        if nums[-1] < target:
            return len(nums)
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = lo + (hi - lo)//2
            if nums[mid] >= target:
                hi = mid 
            else:
                lo = mid + 1
        return lo