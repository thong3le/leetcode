class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n:
            return 0
            
        res = [1,1]
        for _ in range(2, n+1):
            res.append(res[-1] + res[-2])
        return res[n]