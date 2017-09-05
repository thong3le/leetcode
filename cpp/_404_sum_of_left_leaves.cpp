/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 404 - Sum of Left Leaves
*
*    Solution Approach: 
*
*
*
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            if (node->left){
                if (node->left->left == NULL && node->left->right == NULL)
                    result += node->left->val;
                else
                    stack.push(node->left);
            }
            if (node->right && (node->right->left || node->right->right))
                stack.push(node->right);
        }
        return result;
    }
    int sumOfLeftLeaves2(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        if (root->left)
            if (root->left->left == NULL && root->left->right == NULL)
                result += root->left->val;
            else
                result += sumOfLeftLeaves(root->left);
        result += sumOfLeftLeaves(root->right);
        return result;
    }
};

int main() {
	return 0;
}
