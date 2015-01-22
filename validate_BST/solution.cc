class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int prev;
        bool emptyPrev = true, isValid = true;
        inOrderCheck(root, prev, emptyPrev, isValid);
        return isValid;
    }

    void inOrderCheck(TreeNode *n, int &prev, bool &emptyPrev, bool &isValid) {
        if (!n) return;

        inOrderCheck(n->left, prev, emptyPrev, isValid);
        if (!emptyPrev && prev >= n->val) {
            isValid = false;
            return; // no need to traverse further
        }
        prev = n->val;
        if (emptyPrev) emptyPrev = false;

        inOrderCheck(n->right, prev, emptyPrev, isValid);
    }
};

