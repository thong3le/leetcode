class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


from collections import deque
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        queue = deque([root])
    
        res = []
        while len(queue) > 0:
            m = len(queue)
            for i in range(m):
                node = queue.popleft()
                if i == m - 1:
                    res.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return res