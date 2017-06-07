# Author: Thong Le
# Date: 06/06/2017
#
# LeetCode 85 - Maximal Rectangle
#
# Solution Approach: Use largest rectangle in histogram
#
#
#

class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if (len(matrix) == 0 or len(matrix[0]) == 0):
            return 0
        ans = 0
        m, n = len(matrix), len(matrix[0])
        h = [0]*(m+1)
        for j in range(n):
            stack = []
            for i in range(m+1):
                h[i] = h[i] + 1 if i < m and matrix[i][j] == '1' else 0
                while (stack and h[i] < h[stack[-1]]):
                    height = h[stack.pop()]
                    width = i if not stack else i - stack[-1] - 1
                    ans = max(ans, height * width)
                stack.append(i)
        return ans
                    