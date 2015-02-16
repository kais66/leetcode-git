class Solution {
public:
    // gotcha: need to save original left/right child pointer copies, because the pointers may have been changed before they are
    // being visited.
    void flatten(TreeNode *root) {
        TreeNode *prev = NULL;
        flattenRec(root, prev); 
    }
    void flattenRec(TreeNode *root, TreeNode *&prev) {
        if (!root) return;
        TreeNode *l = root->left;
        TreeNode *r = root->right;

        if (prev) { 
            prev->right = root;
            prev->left = NULL;
        }
        prev = root;
        flattenRec(l, prev);
        flattenRec(r, prev);
    }
};
