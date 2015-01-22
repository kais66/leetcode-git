class Solution {
public:
    // http://www.programcreek.com/2013/12/in-place-reorder-a-singly-linked-list-in-java/
    // 1. find the two halves in O(n); 2. reverse the second half in O(n); 3. merge two halves in O(n).
    void reorderList(ListNode *head) {
        if (!head) return;
        if (!head->next) return;

        ListNode *p = head; // fast runner
        ListNode *q = head;

        // find mid list pointer
        //while (p && p->next) {
        while (p && p->next && p->next->next) { // this way, after the loop, q will always points to node before the 2nd list head
            p = p->next->next;
            q = q->next;
        }
        ListNode *temp = q;
        q = q->next;
        temp->next = NULL; // detach

        // reverse second half
        q = reverseList(q);

        // merge
        ListNode *dum = new ListNode(INT_MIN);
        ListNode *tail = dum;
        p = head;
        while (p) {
            tail->next = p;
            tail = tail->next;
            p = p->next;
            
            tail->next = q;
            tail = tail->next;
            if (!q) break;
            q = q->next; 
        }
        delete dum;
    }

    ListNode* reverseList(ListNode *head) {
        if (!head) return head;
        ListNode *rh = head;
        ListNode *cur = head->next;
        rh->next = NULL;
        while (cur) {
            ListNode *pre = cur;
            cur = cur->next;
            pre->next = rh;
            rh = pre;
        }
        return rh;
    }
};
