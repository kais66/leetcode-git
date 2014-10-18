#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

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
        if (adj.empty()) {
            res.push_back(prev_elem);
            return;
        }
        
        //for (auto i : adj) {
        unordered_set<int>::iterator it = adj.begin(), temp = adj.begin();
        //while (it != adj.end()) {
        for (; it != adj.end(); ++it) {
            prev_elem. push_back(*it);
            //cout << "1" << endl;
            adj.erase(*it);
            //cout << "2" << endl;
            getPermRec(res, prev_elem, adj);
            prev_elem.pop_back();
            //cout << "3" << endl;
            adj.insert(*it);
            //cout << "4" << endl;
        }
    }
};

int main() {
    Solution s;
    vector<int> v(1, 1);
    s.permute(v);
    return 0;
}
