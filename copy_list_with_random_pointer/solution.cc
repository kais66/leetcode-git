class Solution {
public:
    // this is with O(n) memory. O(1) memory solution: http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> hash;

        RandomListNode *nhead = new RandomListNode(head->label);
        hash[head] = nhead;
        RandomListNode *nprev = nhead;

        RandomListNode *p = head->next;
        while (p) {
            RandomListNode *n = new RandomListNode(p->label);
            hash[p] = n;
            nprev->next = n;
            nprev = n;
            p = p->next;
        }

        p = head;
        while (p) {
            hash[p]->random = hash[p->random]; 
            p = p->next;
        }
        return nhead;
    }
};
