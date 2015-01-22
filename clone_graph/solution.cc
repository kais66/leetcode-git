class Solution {
public:
    // note visited is implicited tracked by the hashmap
    // http://fisherlei.blogspot.com/2013/12/leetcode-clone-graph-solution.html
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        //unordered_set<UndirectedGraphNode*> visited; 
        UndirectedGraphNode *newn = new UndirectedGraphNode(node->label);
        hash[node] = newn;

        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();
            //if (visited.find(n) != visited.end()) continue;
            //else visited.insert(n);
            UndirectedGraphNode *newn = hash[n];

            for (UndirectedGraphNode *gn : n->neighbors) {
                if (gn) {
                    if (hash.find(gn) == hash.end()) {
                        UndirectedGraphNode *newb = new UndirectedGraphNode(gn->label);
                        hash[gn] = newb;
                        newn->neighbors.push_back(newb);
                        q.push(gn); 
                    } else {
                        newn->neighbors.push_back(hash[gn]);
                    }
                }
            }
        }

        return hash[node];
    }
};
