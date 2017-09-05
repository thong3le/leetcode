/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 543 - Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
    int maxDepth(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;
        int left = maxDepth(root->left, diameter);
        int right = maxDepth(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};


int main() {
	return 0;
}
