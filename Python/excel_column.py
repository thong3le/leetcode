class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        res = 0
        for i in range(n):
            res += ( ord(s[i]) - ord('A') + 1 ) * 26**(n-1-i)
        return res