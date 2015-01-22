class Solution {
public:
    // the function must have public scope
    struct Comp {
        // has to be greater than for min heap
        bool operator() (const ListNode *lhs, const ListNode *rhs) {
            return lhs->val > rhs->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> heap; // note the way priority_queue is declared
        for (ListNode *a : lists) {
            if (a) heap.push(a);
        }

        ListNode dumobj(INT_MIN);
        ListNode *dum = &dumobj;
        ListNode *tail = dum;
        while (!heap.empty()) {
            ListNode *tp = heap.top();
            heap.pop();
            tail->next = tp;
            tail = tail->next;
            if (tp->next) heap.push(tp->next);
        }
        return dum->next;
    }
};


