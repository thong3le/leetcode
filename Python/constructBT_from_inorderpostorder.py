# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        if not inorder or not postorder:
            return None

        root = TreeNode(postorder.pop())
        inorderIndex = inorder.index(root.val)

        root.right = self.buildTree(inorder[inorderIndex+1:], postorder)
        root.left = self.buildTree(inorder[:inorderIndex], postorder)

        return root


    def fastbuildTree(self, inorder, postorder):
        if not inorder:
            return 

        root = TreeNode(postorder.pop())
        stack = [root]

        while True:
            if inorder[-1] == stack[-1].val:
                p = stack.pop();
                inorder.pop();
                if inorder:
                    break
                if stack and inorder[-1] == stack[-1].val:
                    continue
                p.left = TreeNode(postorder.pop())
                stack.append(p.left)
            else:
                p = TreeNode(postorder.pop())
                stack[-1].right = p
                stack.append(p)
        return root
