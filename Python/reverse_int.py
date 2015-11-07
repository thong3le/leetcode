class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if x >= 0:
            res = int("".join(reversed(str(x))))
        else:
            res = -int( "".join(reversed(str(x)[1:])))
        
        return 0 if res > 2147483647 or res < -2147483648 else res