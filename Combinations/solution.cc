class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // k < n
        vector<vector<int> > res;
        if (k > n) return res;
        else {
            vector<int> base;
            solveRec(res, base, n, 1, k);
        }

        return res;
    }
    
    void solveRec(vector<vector<int> > &res, vector<int> &base, int n, int cur_num, int k) {
        int size = base.size();
        if (size == k) {
            res.push_back(base);
            return;
        } 
        
        // cur_num is the number currently being considered for this call
        for (int i=cur_num; i<=n; i++) {
            base.push_back(i);
            solveRec(res, base, n, i+1, k);
            base.pop_back();
        }
    }
};