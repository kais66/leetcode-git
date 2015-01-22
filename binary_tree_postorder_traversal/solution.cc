class Solution {
public:
    // http://leetcode.com/2010/10/binary-tree-post-order-traversal.html
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        
        stack<TreeNode *> sk;
        sk.push(root); // stack contains nodes to be scanned, we have no idea of whether the top is the node to be marked as visited 

        TreeNode *prev = NULL; 
        while (!sk.empty()) {
            TreeNode *n = sk.top(); 
            if (!prev || n == prev->left || n == prev->right) { // going down
                if (n->left) {
                    sk.push(n->left); // because n is not going to be popped, so no need to push right to sk now
                } else if (n->right) {
                    sk.push(n->right);
                } else {
                    ret.push_back(n->val);
                    sk.pop();
                }
            } else if (n->left == prev) {
                if (n->right) {
                    sk.push(n->right);
                } else {
                    ret.push_back(n->val);
                    sk.pop();
               } 
            } else if (n->right == prev) {
                ret.push_back(n->val);
                sk.pop();
            } else { // no relationship, no need to to anything
            }
            prev = n;
        }
        return ret;
    }
};
