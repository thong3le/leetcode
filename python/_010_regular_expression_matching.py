# Author: Thong Le
# Date: June 07, 2017
#
# LeetCode 10 - Regular Expression Matching
#
# Solution Approach: Dynamic Programming (Topdown approach)
#
#
#

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp = {}
        return self.topdown(s, p, 0, 0, dp)
    
    def topdown(self, s, p, i, j, dp):
        if (i == len(s) and j == len(p)):
            return True
        if (j >= len(p)):
            return False
        if (i,j) in dp:
            return dp[(i,j)]
        if (j+1 < len(p)) and (p[j+1] == '*'):
            b1 = self.topdown(s, p, i, j+2, dp)
            if i < len(s) and (p[j] == '.' or p[j] == s[i]):
                b2 = self.topdown(s, p, i+1, j, dp)
                dp[(i,j)] = b1 or b2
            else:
                dp[(i,j)] = b1
        else:
            if i < len(s) and (p[j] == '.' or p[j] == s[i]):
                dp[(i,j)] = self.topdown(s, p, i+1, j+1, dp)
            else:
                dp[(i,j)] = False
        return dp[(i,j)]
        