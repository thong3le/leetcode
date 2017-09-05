/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 501 - Find Mode in Binary Search Tree
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
    int curVal;
    int curCount = 0;
    int maxCount = 0;
    int modeCount = 0;
    vector<int> result;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        result.resize(modeCount);
        modeCount = 0; curCount = 0;
        inorder(root);
        return result;
    }
    
    void handleValue(int val) {
        if (val != curVal) {
            curVal = val;
            curCount = 0;
        }
        curCount++;
        if (curCount > maxCount) {
            maxCount = curCount;
            modeCount = 1;
        } else if (curCount == maxCount){
            if (!result.empty())
                result[modeCount] = curVal;
            modeCount++;
        }
    }
    void inorder(TreeNode* root) {
        TreeNode* cur = root, *prev;
        while (cur) {
            if (cur->left == NULL) {
                handleValue(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right && prev->right != cur) prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    handleValue(cur->val);
                    cur = cur->right;
                }
            }
        }
        
    }
};


int main() {
	return 0;
}
