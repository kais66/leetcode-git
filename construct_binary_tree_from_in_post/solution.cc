class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return NULL;
        int n = inorder.size();
        unordered_map<int, int> nodeInd;
        for (int i=0; i<n; ++i) { nodeInd[inorder[i]] = i; } 
        return createNode(postorder, 0, n-1, inorder, 0, n-1, nodeInd);
    }

    TreeNode *createNode(vector<int> &post, int pi, int pj, vector<int> &in, int ii, int ij, unordered_map<int, int> &hash) {
        if (pi > pj) return NULL;
        TreeNode *root = new TreeNode(post[pj]);
        int ind = hash[post[pj]];
        int num_left = ind - ii;
        root->left = createNode(post, pi, pi+num_left-1, in, ii, ind-1, hash);
        root->right = createNode(post, pi+num_left, pj-1, in, ind+1, ij, hash);
        return root;
    }
};
