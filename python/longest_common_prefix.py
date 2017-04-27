class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        strs = sorted(strs)
        s1 = strs[0]
        s2 = strs[-1]
        if not s1 or not s2:
            return ""
        i = 0
        while i < min(len(s1), len(s2)) and s1[i] == s2[i]:
            i += 1
        return s1[0:i]

    def lcp2(self, strs):
        if not strs:
            return ""
        for i, g in enumerate(zip(*strs)):
            if len(set(g)) > 1:
                return strs[0][:i]
        return min(strs)