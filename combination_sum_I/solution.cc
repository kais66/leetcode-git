class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> base;
        solveRec(res, candidates, base, 0, target);
        return res;
    }
    
    // ind: index of base's last element
    // rem: remain
    void solveRec(vector<vector<int> > &res, vector<int> &cand, vector<int> &base, int ind, int rem) {
        if (!rem) {
            res.push_back(base);
            return;
        }

        for (int i=ind; i<cand.size(); i++) {
            if (cand[i] <= rem) {
                base.push_back(cand[i]);
                solveRec(res, cand, base, i, rem-cand[i]);
                base.pop_back();
            }
        }

    }
};