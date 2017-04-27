class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        lo = self.bs(nums, target)
        hi = self.bs(nums, target + 1)
        
        return [-1,-1] if lo == hi else [lo, hi - 1]
        
    def bs(self, nums, target):
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = lo + (hi - lo)//2
            if nums[mid] >= target:
                hi = mid
            else:
                lo = mid + 1
        return lo