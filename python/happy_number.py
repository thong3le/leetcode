from collections import defaultdict

class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        dic = defaultdict(int)
        n = self.sqr_digits(n)
        while n not in dic:
            dic[n] = 1
            if n == 1:
                return True
            n = self.sqr_digits(n)
        return False
            
    def sqr_digits(self, n):
        return sum(map(lambda x: int(x)**2, str(n)))