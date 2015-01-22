class Solution {
public:
    // this version did not check if visited
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();
            
            UndirectedGraphNode *newn = new UndirectedGraphNode(n->label);
            hash[n] = newn;
            for (UndirectedGraphNode *gn : n->neighbors) {
                if (gn) q.push(gn); 
            }
        }

        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();
            UndirectedGraphNode *newn = hash[n];
            for (UndirectedGraphNode *gn : n->neighbors) {
                if (gn) {
                    q.push(gn);
                    newn->neighbors.push_back(hash[gn]);
                }
            }
        }

        return hash[node];
    }
};
