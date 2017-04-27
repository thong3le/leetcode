class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        for k, v in dic.items():
            if v == 1:
                return k
    def singleNumber2(self, nums):
        return reduce(lambda x, y: x^y, [0] + nums)