class Solution {
public:
    // first cut the linked list into: sorted, unprocessed parts. 
    // note the second while loop
    // INT_MIN->1->3->5
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;                
        dum->next = head;
        ListNode *p = head->next;
        head->next = NULL;
        while (p) {
            ListNode *next = p->next;

            ListNode *q = dum;
            while (q->next && q->next->val <= p->val) { // loop invariant: q->val < p->val
                q = q->next;
            }
            // now: !q->next or q and q->next is the position
            p->next = q->next;
            q->next = p;

            p = next;
        }
        return dum->next;
    }
};
