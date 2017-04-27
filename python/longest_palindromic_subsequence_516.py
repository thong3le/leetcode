class Solution(object):
    def longestPalindromeSubseq1(self, s):
        n = len(s)
        dp = [1] * n
        pre = [0] * n
        for k in xrange(1, n):
            for i in xrange(n-k):
                pre[i] = dp[i]
                if s[i] == s[i+k]:
                    dp[i] = 2 + pre[i+1]
                else:
                    dp[i] = max(dp[i], dp[i+1])
        return dp[0]
        
    def longestPalindromeSubseq(self, s):
        n = len(s)
        dp = [1] * n
        for j in xrange(1, n):
            pre = 0
            for i in reversed(xrange(j)):
                tmp = dp[i]
                dp[i] = 2 + pre if s[j] == s[i] else max(dp[i+1], dp[i])
                pre = tmp
        return dp[0]

s = "b" * 1000
print Solution().longestPalindromeSubseq(s)