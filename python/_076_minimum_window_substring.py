# Author: Thong Le
# Date: 
#
# LeetCode 76 - Minimum Window Substring
#
# Solution Approach: 
#
#
#

from collections import Counter
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        m = Counter(t)
        missing = len(t)
        start, end = 0, 0
        left, d = 0, 1e9
        while end < len(s):
            if m[s[end]] > 0:
                missing -= 1
            m[s[end]] -= 1
            end += 1
            #print m, missing, start, end
            while missing == 0:
                #print (start, end)
                if end - start < d:
                    left, d = start, end - start
                m[s[start]] += 1
                if m[s[start]] > 0:
                    missing += 1
                start += 1
        return s[left: left + d] if d < 1e9 else ""


s = "AAAAAAAAAAAAAAAAADOABECODEBABNC"
t = "AABC"

print(Solution().minWindow(s,t))