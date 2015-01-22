class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        queue<int> levq;
        queue<TreeNode *> nodeq;                
        nodeq.push(root);
        int curLev = 1;
        levq.push(curLev);

        while (!nodeq.empty()) {
            TreeNode *nd = nodeq.front();
            int lev = levq.front();
            nodeq.pop();
            levq.pop();
            if (ret.size() < lev) ret.push_back(vector<int>());
            ret[lev-1].push_back(nd->val);
            
            if (nd->left) {
                nodeq.push(nd->left);
                levq.push(lev + 1);
            }

            if (nd->right) {
                nodeq.push(nd->right);
                levq.push(lev + 1);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
