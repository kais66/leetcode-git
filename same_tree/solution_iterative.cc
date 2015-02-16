class Solution {
public:
    // level order traveral to verify
    bool sameTree(TreeNode *r1, TreeNode *r2) {
        if (!r1) return (r2 == NULL); 
        if (!r2 || r1->val != r2->val) return false;
        queue<TreeNode*> q1;
        q1.push(r1);
        queue<TreeNode*> q2;
        q2.push(r2);
        while (!q1.empty()) {
            TreeNode *n1 = q1.front();
            q1.pop();
            TreeNode *n2 = q2.front();
            q2.pop();
            if (n1->left) {
                if (!n2->left || n1->left->val != n2->left->val) return false;
                q1.push(n1->left);
                q2.push(n2->left);
            } else {
                if (n2->left) return false;
            }
            if (n1->right) {
                if (!n2->right || n1->right->val != n2->right->val) return false;
                q1.push(n1->right);
                q2.push(n2->right);
            } else {
                if (n2->right) return false;
            }
        }
        return true;
    }
};
