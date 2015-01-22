class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head; 
        int i = 1;
        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        ListNode *prev = dum; // prev is corresponding to counter value 0
        dum->next = head;
        ListNode *p = head;
        int cnt = 0;
        while (p) {
            cnt++; 
            if (cnt % k == 0) {
                prev = reverseExclusively(prev, p->next);
                p = prev->next;
            } else {
                p = p->next;
            }
        }
        return dum->next;
    }

    // Reverse a link list between a and b exclusively
    // return the tail of reversed list
    ListNode *reverseExclusively(ListNode *a, ListNode *b) {
        ListNode *ret = a->next;
        ListNode *head = a->next;
        ListNode *n = head->next;

        while (n != b) {
            ListNode *temp = n;
            n = n->next;
            temp->next = head;
            head = temp;
        }
        a->next = head;
        ret->next = b;
        return ret;
    }
}
