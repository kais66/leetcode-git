class Solution {
public:
    // consider: it take k iterations to meet; non-cycle: from head to cycle-start; cycle-meet: from cycle-start to meet
    // meet-cycle: from meet to cycle start. Then k == non-cycle + cycle-meet == cycle-meet + meet-cycle
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *a = head;
        ListNode *b = head;
        bool cycle = false;
        while (a->next && a->next->next) {
            a = a->next->next;
            b = b->next;
            if (a == b) {
                cycle = true;
                break;
            }
        }
        if (!cycle) return NULL;
        b = head;
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
