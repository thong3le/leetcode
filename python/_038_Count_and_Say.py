class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for _ in range(n-1):
            s = self.f(s)
        return s
        
    def f(self, s):
        pos = [0] + filter(lambda x: s[x-1] != s[x], range(1, len(s))) + [len(s)]
        res = [str(len(s[pos[i]:pos[i+1]])) + s[pos[i]] for i in range(len(pos)-1)]
        return "".join(res)