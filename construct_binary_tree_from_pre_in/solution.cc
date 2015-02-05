class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return NULL;
        int n = preorder.size();
        unordered_map<int, int> nodeInd;
        for (int i=0; i<n; ++i) { nodeInd[inorder[i]] = i; } 
        return createNode(preorder, 0, n-1, inorder, 0, n-1, nodeInd);
    }

    TreeNode *createNode(vector<int> &pre, int pi, int pj, vector<int> &in, int ii, int ij, unordered_map<int, int> &hash) {
        if (pi > pj) return NULL;
        TreeNode *root = new TreeNode(pre[pi]);
        int ind = hash[pre[pi]];
        int num_left = ind - ii;
        root->left = createNode(pre, pi+1, pi+num_left, in, ii, ind-1, hash);
        root->right = createNode(pre, pi+num_left+1, pj, in, ind+1, ij, hash);
        return root;
    }
};
