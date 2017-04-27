class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        table = dict()
        alphabet = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        if len(s) <= 10:
            return res
        for i in range(len(s) - 10 + 1):
            v = 1
            for j in range(i, i+10):
                v <<= 2
                v |= alphabet[s[j]]
            if v in table and table[v] < 2:
                res.append(s[i:(i+10)])
                table[v] += 1
            elif v not in table:
                table[v] = 1
        return res

    def findRepeatedDnaSequences2(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        table = dict()
        if len(s) <= 10:
            return res
        for i in range(len(s) - 10 + 1):
            word = s[i:(i+10)]
            if word in table and table[word] == 1:
                res.append(word)
                table[word] += 1
            elif word not in table:
                table[word] = 1
        return res
