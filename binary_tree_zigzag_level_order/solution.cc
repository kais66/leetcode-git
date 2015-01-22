class Solution {
public:
    // psudo code: 
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        stack<TreeNode *> sk1;
        stack<TreeNode *> sk2;
        sk1.push(root);

        while (!sk1.empty() || !sk2.empty()) {
            vector<int> v1;
            while (!sk1.empty()) {
                TreeNode *n = sk1.top();
                sk1.pop();
                v1.push_back(n->val);

                if (n->left) sk2.push(n->left); 
                if (n->right) sk2.push(n->right);
            }
            if (!v1.empty()) ret.push_back(v1);
            
            vector<int> v2;
            while (!sk2.empty()) {
                TreeNode *n = sk2.top();
                sk2.pop();
                v2.push_back(n->val);

                if (n->right) sk1.push(n->right);
                if (n->left) sk1.push(n->left); 
            }
            if (!v2.empty()) ret.push_back(v2);
        }
        return ret;
    }
};
