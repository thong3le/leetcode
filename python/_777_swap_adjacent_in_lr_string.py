class Solution(object):
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        n = len(start)
        i, j = 0, 0
        while i < n and j < n:
            if start[i] == 'X':
                i += 1
            elif end[j] == 'X':
                j += 1
            else:
                if (start[i] != end[j]) or (start[i] == 'R' and i > j) or (start[i] == 'L' and j > i):
                    return False
                i += 1
                j += 1
        while i < n:
            if start[i] != 'X':
                return False
            i += 1
        while j < n:
            if end[j] != 'X':
                return False
            j += 1
        
        return True
        