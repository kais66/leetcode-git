class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBSTRec(num, 0, num.size()-1);       
    }

    // need a recursive function, taking start and end indices as input
    TreeNode *toBSTRec(vector<int> &num, int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *n = new TreeNode(num[mid]);
        n->left = toBSTRec(num, start, mid-1);
        n->right = toBSTRec(num, mid+1, end);
        return n;
    }
};
