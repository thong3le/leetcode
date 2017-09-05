/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL || root1->val != root2->val) return false;
        return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return t == NULL;
        return sameTree(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};