class Solution:
    # @param s : string
    # @param p : string
    # @return an integer
    def isMatch(self, s, p):
        n = len(s)
        prev = [True] + [False] * n
        cur = [False] * (n+1)
        prev[0] = True
        r = 1
        while r < len(p):
            if r < len(p) - 1 and p[r] != '*' and p[r+1] == '*':
                for i in range(n+1):
                    cur[i] = prev[i]
                    if i > 0 and (p[r] == s[i-1] or p[r] == '.'):
                        cur[i] = cur[i] or cur[i-1]
                r += 2
            else:
                cur[0] = False
                for i in range(1, n+1):
                    cur[i] = prev[i-1] and (p[r] == '.' or p[r] == s[i-1])
                r += 1
            for i in range(n+1):
                prev[i] = cur[i]
            

        return prev[n]

    def isMatch2(self, s, p):
        return self.topdown(s, p, len(s), len(p), {})
    def topdown(self, s, p, n, m, dp):
        if m == 0: return True if n == 0 else False
        if m == 1: return True if n == 1 and (p[0] == '.' or p[0] == s[0]) else False
        if (n, m) in dp: return dp[(n, m)]
        if p[m-1] != '*':
            if n == 0 or (p[m-1] != '.' and p[m-1] != s[n-1]):
                return False
            dp[(n,m)] = dp[(n-1, m-1)] if (n-1, m-1) in dp else self.topdown(s, p, n-1, m-1, dp)
        else:
            if p[m-2] == '*':
                return False
            dp[(n,m)] = dp[(n, m-2)] if (n, m-2) in dp else self.topdown(s, p, n, m-2, dp)
            if n > 0 and (p[m-2] == s[n-1] or p[m-2] == '.'):
                b = dp[(n-1, m)] if (n-1, m) in dp else self.topdown(s, p, n-1, m, dp)
                dp[(n,m)] = dp[(n,m)] or b
        return dp[(n,m)]
    # def topdown(self, s, p, n, m, dp):
    #     if m == 0: return True if n == 0 else False
    #     if m == 1: return True if n == 1 and (p[0] == '.' or p[0] == s[0]) else False
    #     if (n, m) in dp: return dp[(n, m)]
    #     if p[m-1] != '*':
    #         if n == 0 or (p[m-1] != '.' and p[m-1] != s[n-1]):
    #             return False
    #         dp[(n,m)] = dp[(n-1, m-1)] if (n-1, m-1) in dp else self.topdown(s, p, n-1, m-1, dp)
    #     else:
    #         if p[m-2] == '*':
    #             return False
    #         dp[(n,m)] = dp[(n, m-2)] if (n, m-2) in dp else self.topdown(s, p, n, m-2, dp)
    #         if n > 0 and (p[m-2] == s[n-1] or p[m-2] == '.'):
    #             b = dp[(n-1, m)] if (n-1, m) in dp else self.topdown(s, p, n-1, m, dp)
    #             dp[(n,m)] = dp[(n,m)] or b
    #     return dp[(n,m)]


s= "ac"
p= "a*b*c*dkfjdkf*dfd*"

print Solution().isMatch(s, p)
