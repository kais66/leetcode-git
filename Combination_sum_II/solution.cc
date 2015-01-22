class Solution {
public:
    // special case: num has duplicates, e.g. num=[1,1], target=1. Should return only [1].
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        sort(num.begin(), num.end());

        vector<int> base;
        solveRec(ret, num, base, 0, target);
        return ret;
    }

    void solveRec(vector<vector<int> > &ret, vector<int> &num, vector<int> &base, int ind, int rem) {
        // return condition should be all numbers have been evaluated, or rem==0. push_back condition is rem==0
        if (rem == 0) {
            ret.push_back(base); 
            return;
        }

        for (int i=ind; i<num.size(); ++i) {
            if (i > ind && num[i] == num[i-1]) continue;
            if (rem - num[i] >= 0) {
                base.push_back(num[i]);
                solveRec(ret, num, base, i+1, rem-num[i]); 
                base.pop_back();
            }
        }
    }
};
