class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = num
        while s >= 10:
            s = sum(map(int, str(s)))
        return s