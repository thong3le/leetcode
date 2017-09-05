/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 108 - Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
    TreeNode* buildBST(vector<int>& nums, int i, int j) {
        if (j < i) return NULL;
        int mid = (i+j)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, i, mid-1);
        root->right = buildBST(nums, mid+1, j);
        return root;
    }
};


int main() {
	return 0;
}
