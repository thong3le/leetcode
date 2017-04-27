# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def isValidBST(self, root, lowerbound = -2**63, upperbound = 2**63 - 1):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        if lowerbound >= root.val or root.val >= upperbound:
            return False
        return self.isValidBST(root.left, lowerbound, root.val) and self.isValidBST(root.right, root.val, upperbound)