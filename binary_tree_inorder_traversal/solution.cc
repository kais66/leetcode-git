class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;

        stack<TreeNode *> sk; // stack contains nodes whose left child is visited.

        // n is the current node to be traversed tentatively
        TreeNode *n = root;
        while (n || !sk.empty()) {
            while (n) {
                sk.push(n);
                n = n->left;
            }
            
            TreeNode *top = sk.top();
            sk.pop();
            ret.push_back(top->val);
            if (top->right) n = top->right;
        }

        return ret;
    }
};
