# Author: Thong Le
# Date: 
#
# LeetCode 129 - Sum Root to Leaf Numbers
#
# Solution Approach: 
#
#


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        return self.dfs(root, root.val)
    
    def dfs(self, root, cur):
        ans = 0
        if root.left:
            ans += self.dfs(root.left, cur*10 + root.left.val)
        if root.right:
            ans += self.dfs(root.right, cur*10 + root.right.val)
        if root.left is None and root.right is None:
            return cur
        return ans#
