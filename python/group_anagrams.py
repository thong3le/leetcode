class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = {}
        if not strs:
            return []
        for word in strs:
            key = ''.join(sorted(word))
            if key in dic:
                dic[key].append(word)
            else:
                dic[key] = [word]
        ret = []
        for key in dic:
            ret.append(dic[key])
        return ret

IN = ["and", "dan"]
print Solution().groupAnagrams(IN)