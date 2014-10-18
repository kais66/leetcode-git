class Solution {
public:
    /* two ways of thinking: use DFS, build an abstract tree (may not be as efficient) */
    /* or: generic recursion. take out the first element, do permute for the remaining array, then insert the first one */
    vector<vector<int> > permute(vector<int> &num) {
        unordered_set<int> adj(num.begin(), num.end());
        vector<int> prev_elem;
        vector<vector<int> > res;
        getPermRec(res, prev_elem, adj);
        return res;
    }
    
    // adj is the adjacency list.
    void getPermRec(vector<vector<int> > &res, vector<int> &prev_elem, unordered_set<int> &adj)
    {
        if (adj.empty()) return;
        if (adj.size() == 1) {
            for (auto i : adj) prev_elem.push_back(i);
            res.push_back(prev_elem);
            return;
        }
        
        for (auto i : adj) {
            vector<int> v = prev_elem;
            v. push_back(i);
            unordered_set<int> a = adj;
            a. erase(i);
            getPermRec(res, v, a);
        }
    }
};