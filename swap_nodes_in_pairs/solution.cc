class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;                
        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        dum->next = head;
        ListNode *p = head;
        ListNode *prev = dum;
        int i = 0;
        while (p) {
            i++;
            if (i % 2 == 0) {
                ListNode *sec = prev->next;

                sec->next = p->next;
                p->next = sec;
                prev->next = p;

                prev = sec;
                p = sec->next;
            } else {
                p = p->next;
            }
        }
        return dum->next;
    }
};
