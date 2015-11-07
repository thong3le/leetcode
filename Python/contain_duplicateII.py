class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        
        if k + 1 >= len(nums):
            return len(nums) > len(set(nums))
        for i in range(len(nums) - k + 2):
            if len(nums[i:(i+k+1)]) > len(set(nums[i:(i+k+1)])):
                return True
        return False

    def containsNearbyDuplicate2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic = {}
        for i in range(len(nums)):
            if nums[i] in dic and i - dic[nums[i]] <= k:
                return True
            else:
                dic[nums[i]] = i
        return False