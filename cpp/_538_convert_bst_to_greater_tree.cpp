/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 538 - Convert BST to Greater Tree
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
    int cur_sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root){
        if (!root) return;
        traverse(root->right);
        root->val = (cur_sum += root->val);
        traverse(root->left);
    }
};


int main() {
	return 0;
}
