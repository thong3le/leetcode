class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        if len(words) != len(pattern):
            return False
        dic = {}
        for c, w in zip(pattern, words):
            if c in dic and w != dic[c]:
                return False
            elif c not in dic:
                if w in dic.values():
                    return False
                else:
                    dic[c] = w
        return True

    def wordPattern2(self, pattern, str):
        words = str.split()
        return len(pattern) == len(words) and len(set(zip(pattern, words))) == len(set(pattern)) == len(set(words))

    def wordPattern3(self, pattern, str):
         words = str.split()
        return map(pattern.find, pattern) == map(words.index, words)