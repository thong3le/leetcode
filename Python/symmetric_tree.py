class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.isSymmetricHelper(root.left, root.right)
    
    def isSymmetricHelper(self, left, right):
        """
        :type left: TreeNode
        :type right: TreeNode
        :rtype: bool
        """
        if not left or not right:
            return left == right
        if left.val != right.val:
            return False
        return self.isSymmetricHelper(left.left, right.right) and self.isSymmetricHelper(left.right, right.left)
        