class Solution {
public:
    // n: list length. List is the same when it's rotated to the right by n places.
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k==0) return head; 
        
        ListNode *p = head;
        int i = 1;
        for (; i<=k; ++i) { // either move pointer k times or less, if length is less than k+1
            p = p->next;
            if (!p) break;
        }

        // length is i, and k >= i
        if (!p) {
            k = k % i; 
            if (k == 0) return head;
            p = head;
            for (int j=0; j<k; ++j) 
                p = p->next;
        }
        // now p and q are k places apart
        ListNode *q = head;
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        ListNode *ret = q->next;
        q->next = NULL;
        p->next = head;
        return ret;
    }
};
