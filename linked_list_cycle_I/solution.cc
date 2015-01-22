class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *a = head; // fast runner
        ListNode *b = head;
                        
        while (a->next && a->next->next) {
            a = a->next->next;
            b = b->next;
            if (a == b) return true;
        }
        return false;
    }
};
