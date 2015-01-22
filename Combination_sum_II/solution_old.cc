class Solution {
public:
    // special case: num has duplicates, e.g. num=[1,1], target=1. Should return only [1].
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        vector<int> base;
        solveRec(res, num, base, 0, target);
        return res;
    }
    
    void solveRec(vector<vector<int> > &res, vector<int> &num, vector<int> &base, int ind, int rem) {
        if (!rem) {
            res.push_back(base);
            return;
        }

        for (int i=ind; i<num.size(); i++) {
            if (num[i] <= rem) {
                if (i>ind && num[i] == num[i-1]) continue; // same way to eliminate dup with 3Sum/4Sum
                
                base.push_back(num[i]);
                solveRec(res, num, base, i+1, rem-num[i]);
                base.pop_back();
            }
        }
    }
};