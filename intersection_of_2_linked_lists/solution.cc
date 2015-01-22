class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA;
        ListNode *b = headB;                
        int l1 = getLen(a);
        int l2 = getLen(b);
        if (l1 > l2) {
            for (int i=l1-l2; i>0; --i) {
                a = a->next; 
            }
        } else if (l2 > l1) {
            for (int i=l2-l1; i>0; --i) {
                b = b->next;
            }
        }
        while (a) {
            if (a == b) return a;
            a = a->next;
            b = b->next;    
        }
        return NULL;
    }

    int getLen(ListNode *a) {
        int i = 0;
        while (a) {
            i++;
            a = a->next;
        }
        return i;
    }
};
