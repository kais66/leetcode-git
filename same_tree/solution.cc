class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p || !q) 
      return (!p && !q); // if one of them is NULL, then IFF both are NULL, they are the same tree
    else if (p->val != q->val)
      return false;

    bool l, r;
    l = isSameTree(p->left, q->left);
    r = isSameTree(p->right, q->right);
    return (l && r);
  }
};
