#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int min_diff = INT_MAX;
    int previous = -1;
    int getMinimumDifference(TreeNode *root) {
        if (root->left != NULL) getMinimumDifference(root->left);
        if (previous >= 0) min_diff = min(min_diff, root->val - previous);
        previous = root->val;
        if (root->right != NULL) getMinimumDifference(root->right);
        return min_diff;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout << (new Solution())->getMinimumDifference(root) << endl;
    return 0;
}
