class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0; // empty tree should have depth as 0

        int mind = INT_MAX;    
        findMinDepth(root, 0, mind);
        return mind;
    }
    
    void findMinDepth(TreeNode *root, int d, int &mind) {
        if (!root) return;
        d++;
        if (!root->left && !root->right) {
            if (d < mind) mind = d;
            return;
        }
        findMinDepth(root->left, d, mind);
        findMinDepth(root->right, d, mind);
    }
};
