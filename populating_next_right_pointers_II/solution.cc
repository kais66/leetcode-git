class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = root;                
        p->next = NULL;
        while (p) { // top to bottom, assuming p's level is already done, connect the next level
            TreeLinkNode *q = p;
            p = NULL;
            while (q) { // left to right
                TreeLinkNode *chd = NULL;
                if (q->left && q->right) { 
                    q->left->next = q->right; 
                    chd = q->right;
                } else if (q->left) { chd = q->left; }
                else if (q->right) { chd = q->right; }

                if (!p) { p = (q->left ? q->left : q->right); }
                q = q->next;

                TreeLinkNode *qnext = q;
                if (chd) {
                    chd->next = NULL;
                    while (qnext && chd->next == NULL) {
                        if (qnext->left) chd->next = qnext->left;
                        else if (qnext->right) chd->next = qnext->right;
                        else qnext = qnext->next;
                    }
                }
            }
        }
    }
};
