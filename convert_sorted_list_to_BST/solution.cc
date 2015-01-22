class Solution {
public:
    // http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        int i = 1; 
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            i++;
        }
        return createTree(head, 0, i-1);
    }
    // start and end are only for counting how many nodes are left to be created.
    TreeNode* createTree(ListNode *&head, int start, int end) { // have to pass pointer by reference
        if (start > end) return NULL;
        int mid = (start + end) / 2; 
        TreeNode *left = createTree(head, start, mid-1);
        TreeNode *t = new TreeNode(head->val); // this has to come in-between creation of left and right
        head = head->next;
        TreeNode *right = createTree(head, mid+1, end);
        t->left = left;
        t->right = right;
        return t;
    }
};
