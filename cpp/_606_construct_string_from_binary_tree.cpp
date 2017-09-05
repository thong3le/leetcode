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
    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string result = to_string(t->val);
        if (t->left) result += "(" + tree2str(t->left) + ")";
        if (t->right){
            if (t->left == NULL) result += "()";
            result += "(" + tree2str(t->right) + ")";
        }
        return result;
    }
};