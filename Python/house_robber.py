class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        res = [0, nums[0]]
        for e in nums[1:]:
            res.append(max(res[-1], res[-2] + e))
        return res[len(nums)]