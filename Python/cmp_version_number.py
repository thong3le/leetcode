class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        a = map(int, version1.split('.'))
        b = map(int, version2.split('.'))
        
        for i in range(max(len(a), len(b))):
            gap = (a[i] if i < len(a) else 0) - (b[i] if i < len(b) else 0)
            if gap != 0:
                return -1 if gap < 0 else 1
        return 0