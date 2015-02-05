class Solution {
public:
    // WRONG: NULL root!!
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;                
        p->next = NULL;
        while (p) { // assuming p's level is already done, connect the next level
            TreeLinkNode *q = p;
            p = NULL;
            while (q) {
                TreeLinkNode *chd = NULL;
                if (q->left && q->right) { 
                    q->left->next = q->right; 
                    chd = q->right;
                } else if (q->left) { chd = q->left; }
                else if (q->right) { chd = q->right; }

                if (!p) { p = (q->left ? q->left : q->right); }
                q = q->next;

                TreeLinkNode *qnext = q->next;
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
