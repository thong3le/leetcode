# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.previous = -1
        self.ans = float('inf')
        self.min_diff(root)
        return self.ans
    
    def min_diff(self, root):
        if root.left:
            self.min_diff(root.left)
        if self.previous >= 0:
            self.ans = min(self.ans, root.val - self.previous)
        self.previous = root.val
        if root.right:
            self.min_diff(root.right)