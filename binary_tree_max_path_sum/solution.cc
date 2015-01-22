class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int msum = INT_MIN; 
        getMaxDownPathSum(root, msum);
        return msum;
    }

    // max path sum starts from root to any node down and root itself
    int getMaxDownPathSum(TreeNode *root, int &msum) {
        if (!root) return 0;

        int l, r;
        l = getMaxDownPathSum(root->left, msum); 
        r = getMaxDownPathSum(root->right, msum); 

        int temp_msum = root->val;
        if (l > 0) temp_msum += l;
        if (r > 0) temp_msum += r;
        if (temp_msum > msum) msum = temp_msum;

        // return root->val + max(l, r);  WRONG: see last comment 
        return (l>0 || r>0) ? root->val + max(l, r) : root->val;
    }
}
