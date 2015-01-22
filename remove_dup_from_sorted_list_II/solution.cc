class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        dum->next = head;

        ListNode *prev = dum; // prev is a guaranteed singleton
        ListNode *p = head;
        int dup = -1;
        while (p) {
            // this block greatly simplifies code
            if (p->next && p->val == p->next->val) {
                int dup = p->val;
                while (p && p->val == dup) {
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                }
                continue; 
            } 
            prev = p; 
            p = p->next;
        }

        return dum->next;
    }
};


