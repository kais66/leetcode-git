class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n) return head;

        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        dum->next = head;
        ListNode *p = dum;
        int i = 0;
        while (p && i < m-1) { // stop at node m-1
            p = p->next;
            i++;
        }
        
        ListNode *tail = p;  // tail of non-reversed
        p = p->next; // p is node m
        ListNode *rt = p; // this won't change
        ListNode *rh = p; // this pointer will move
        

        p = p->next;
        ListNode *prev = NULL;
        for (i=m+1; i<=n; ++i) {
            ListNode *next = p->next;
            p->next = rh;
            rh = p;
            p = next;
        }
        tail->next = rh; // connect non-reversed with reversed head
        rt->next = p; // connect reversed tail with non-reversed
        return dum->next;
    }
};
