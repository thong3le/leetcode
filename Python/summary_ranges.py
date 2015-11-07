class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []
        n = len(nums)
        res = []
        r = [nums[0]]
        for i in range(1, n):
            if nums[i-1] + 1 == nums[i]:
                r.append(nums[i])
            else:
                if len(r) > 1:
                    res.append(str(r[0]) + "->" + str(r[-1]))
                elif len(r) == 1:
                    res.append(str(r[0]))
                r = [nums[i]]
        if len(r) > 1:
            res.append(str(r[0]) + "->" + str(r[-1]))
        elif len(r) == 1:
            res.append(str(r[0]))
        return res