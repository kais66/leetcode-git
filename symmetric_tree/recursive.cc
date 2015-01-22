class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        else return isMirrorTree(root->left, root->right); 
    }

    bool isMirrorTree(TreeNode *lrt, TreeNode *rrt) {
        if (!lrt || !rrt) return (!lrt && !rrt);

        if (lrt->val != rrt->val) return false;
        else return isMirrorTree(lrt->left, rrt->right) && isMirrorTree(lrt->right, rrt->left);
    }
};
