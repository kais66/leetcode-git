class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<int> base;
        int n = S.size();
        getSubsets(S, -1, res, base, n);
        return res;
    }
    
    /* 'pos' is the starting position to add element to base, to build a new subset */
    /* 'base' is the set of elements which were passed along by function caller */
    void getSubsets(vector<int> &S, int ind, vector<vector<int> > &res, vector<int> &base, int n)
    {
        if (ind >= 0)
            base.push_back(S[ind]);
        res.push_back(base);
        
        int nbr_pos = ind + 1;
        for (; nbr_pos<n; nbr_pos++) {
            getSubsets(S, nbr_pos, res, base, n);
        }
        if (ind >= 0) base.pop_back(); // important
    }
};