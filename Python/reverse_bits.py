class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int("".join(reversed(bin(n)[2:].zfill(32))), 2)