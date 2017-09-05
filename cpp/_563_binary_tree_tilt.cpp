/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 563 - Binary Tree Tilt
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
    int tilt = 0;
public:
    int findTilt(TreeNode* root) {
        post_order(root);
        return tilt;
    }
    int post_order(TreeNode* root){
        if (root == NULL) return 0;
        int left = post_order(root->left);
        int right = post_order(root->right);
        tilt += abs(left-right);
        return left + right + root->val;
    }
};


int main() {
	return 0;
}
