class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        // assuming root is not NULL
        if (!root->left && !root->right) return (sum == root->val);
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }                
};
