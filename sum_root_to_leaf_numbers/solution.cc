class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0, base = 0;
        sumNumRec(root, base, sum);
        return sum; 
    }

    void sumNumRec(TreeNode *n, int base, int &sum) {
        if (!n) return;
        if (!n->left && !n->right) {
            sum += base * 10 + n->val;
            return;
        }
        base += base * 10 + n->val;
        sumNumRec(n->left);
        sumNumRec(n->right);
    }
};
