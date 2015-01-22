class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) return head;

        // following line generate a compile error: Line 14: taking address of temporary [-fpermissive]
        ListNode *sdum = &(ListNode(INT_MIN)); // dum node to small list
        ListNode *stail = sdum;
        ListNode *ldum = &(ListNode(INT_MIN));
        ListNode *ltail = sdum;

        ListNode *p = head;
        while (p) {
            ListNode *next = p->next;
            if (p->val < x) {
                stail->next = p;
                stail = stail->next;
                // also wrong here, need to point tail->next to NULL
            } else {
                ltail->next = p;
                ltail = ltail->next;
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


