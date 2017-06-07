# Author: Thong Le
# Date: 
#
# LeetCode 32 - Longest Valid Parentheses
#
# Solution Approach: 
#
#
#

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            else:
                if stack and s[stack[-1]] == '(':
                    stack.pop()
                else:
                    stack.append(i)
        if not stack:
            return len(s)
        
        right, left = len(s), 0
        longest = 0
        while stack:
            left = stack.pop()
            longest = max(longest, right - left - 1)
            right = left
        return max(longest, right)

s = "()"
print Solution().longestValidParentheses(s)