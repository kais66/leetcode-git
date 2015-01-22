class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dum = new ListNode(INT_MIN);                
        ListNode *t = dum;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                t->next = l1;
                l1 = l1->next;
            } else {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
            t->next = NULL;
        }
        if (l1) t->next = l1;
        if (l2) t->next = l2;

        ListNode *h = dum->next;
        delete dum;
        return h;
    }
};
