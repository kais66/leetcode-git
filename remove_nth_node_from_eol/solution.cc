class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return NULL;

        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        dum->next = head;
        ListNode *p = dum; // fast runner                     

        for (int i=0; i<n; ++i) {
            p = p->next;
            if (!p) return head;
        }
        ListNode *q = dum;
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        ListNode *d = q->next;
        q->next = q->next->next;
        delete d;
        return dum->next;
    }
};
