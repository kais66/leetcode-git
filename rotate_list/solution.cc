class Solution {
public:
    // http://fisherlei.blogspot.com/2013/01/leetcode-rotate-list.html
    // n: list length. List is the same when it's rotated to the right by n places.
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;

        int n = 1; // hold the length of list
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            n++;
        }
        p->next = head;
        int ind = n - k % n;
        ListNode *q = head;
        for (int i=1; i<ind; ++i) {
            q = q->next;
        }
        ListNode *ret = q->next;
        q->next = NULL;
        return ret;
    }
};
