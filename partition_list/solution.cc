class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) return head;

        ListNode sdumo(INT_MIN);
        ListNode *sdum = &sdumo; // dum node to small list
        ListNode *stail = sdum;
        ListNode ldumo(INT_MIN);
        ListNode *ldum = &ldumo;
        ListNode *ltail = ldum;

        ListNode *p = head;
        while (p) {
            ListNode *next = p->next;
            if (p->val < x) {
                stail->next = p;
                stail = stail->next;
                stail->next = NULL;
            } else {
                ltail->next = p;
                ltail = ltail->next;
                ltail->next = NULL;
            }
            p = next;
        }
        if (stail != sdum) {
            stail->next = ldum->next;
            return sdum->next;
        } else {
            return ldum->next;
        }
    }
};


