class Solution {
public:
    // always ask first: what is a "balanced" tree defined to be.
    bool isBalanced(TreeNode *root) {
        bool isBal = true; 
        getMaxDepth(root, isBal);
        return isBal;
    }

    int getMaxDepth(TreeNode *root, bool &isBal) {
        if (!root) return 0;
        int l, r;
        l = getMaxDepth(root->left, isBal);
        r = getMaxDepth(root->right, isBal);
        if (abs(l - r) > 1) isBal = false;
        return (max(l, r) + 1);
    }
};
