class Solution {
public:
    // have to visit every node, because even if duplicates, need to release every node's memory (hence visit every node)
    // because head node will anyway be there (required to keep at least one occurance), no need for dummy head
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode *prev = head;
        ListNode *cur = prev->next;
        while (cur) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next; 
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
