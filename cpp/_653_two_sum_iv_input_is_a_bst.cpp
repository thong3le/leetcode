class Solution {
public:
    bool search(TreeNode* root, TreeNode* cur, int x){
        if (root == NULL) return false;
        return (root->val == x) && (root != cur) || (root->val < x) && search(root->right, cur, x) || (root->val > x) && search(root->left, cur, x);
    }
    
    bool traverse(TreeNode* root, TreeNode* cur, int k){
        if (cur == NULL) return false;
        return search(root, cur, k- (cur->val)) || traverse(root, cur->left, k) || traverse(root, cur->right, k);
    }
    bool findTarget(TreeNode* root, int k){
        return traverse(root, root, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if (root == NULL) return false;
        if (set.find(k-root->val) != set.end()) return true;
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }
    bool findTarget2(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    
    void inorder(TreeNode* root, vector<int>& result){
        if (root->left) inorder(root->left, result);
        result.push_back(root->val);
        if (root->right) inorder(root->right, result);
    }
    
    bool findTarget3(TreeNode* root, int k) {
        if (root == NULL) return false;
        vector<int> nums;
        inorder(root, nums);
        for(int i = 0, j = nums.size() - 1; i < j;){
            if (nums[i] + nums[j] == k) return true;
            else if (nums[i] + nums[j] < k) i++;
            else j--;
        }
        return false;
    }
};