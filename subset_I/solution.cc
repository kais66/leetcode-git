class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        if (S.empty()) return ret;
        
        sort(S.begin(), S.end());
        vector<int> base;
        solveRec(ret, base, 0, S);
        return ret;
    }

    void solveRec(vector<vector<int> > &ret, vector<int> &base, int ind, vector<int> &s) {
        int n = s.size();
        if (ind == n) {
            ret.push_back(base);
            return; 
        }

        for (int i=ind; i<n; ++i) {
            base.push_back(s[i]);
            solveRec(ret, base, i+1, s);
            base.pop_back();
        }
        solveRec(ret, base, n, s);
    }
};
