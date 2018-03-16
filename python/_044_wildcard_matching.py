# Author: Thong Le
# Date: June 08, 2017
#
# LeetCode 44 - Wildcard Matching
#
# Solution Approach: DP
#
#
#

class Solution(object):
    
    def isMatch(self, s, p):
        n = len(s)
        dp = [True] + [False]*n
        print dp
        for i in p:
            if i != '*':
                for j in reversed(range(n)):
                    dp[j+1] = dp[j] and (i == s[j] or i == '?')
            else:
                for j in range(1, n+1):
                    dp[j] = dp[j-1] or dp[j]
            dp[0] = dp[0] and i == '*'
            print dp
        return dp[-1]



s = "abcdefe"
p = "a?*?f"

print(Solution().isMatch(s,p))