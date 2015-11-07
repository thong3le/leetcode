# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.rightSideViewHelper(root, 0, result)
        return result
    
    def rightSideViewHelper(self, node, result, depth):
        if not node:
            return
        if len(result) == depth:
            result.append(node.val)
        self.rightSideViewHelper(node.right, result, depth+1)
        self.rightSideViewHelper(node.left, result, depth+1)