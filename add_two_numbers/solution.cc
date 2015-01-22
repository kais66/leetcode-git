class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dumobj(INT_MIN);                
        ListNode *dum = &dumobj;

        int carry = 0;
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *tail = dum;
        while (p || q) { // note the terminating condition. This way it handles all situations in a single while loop
            int pv = (p ? p->val : 0);
            int qv = (q ? q->val : 0);
            int sum = pv + qv + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry) 
            tail->next = new ListNode(1);

        return dum->next;
    }
};
