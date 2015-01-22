class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> sk; // stack contains nodes to be visited
        sk.push(root);
        while (!sk.empty()) {
            TreeNode *n = sk.top();
            sk.pop();

            res.push_back(n->val); // visit n

            if (n->right) sk.push(n->right); // because right child is visited last, it's first pushed to stack
            if (n->left) sk.push(n->left);
        }
        return res;
    }
};
