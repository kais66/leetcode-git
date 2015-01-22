class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;

        vector<int> base;
        int n = num.size();
        vector<bool> avail(n, true);
        solveRec(ret, base, 0, avail, num);
        return ret;      
    }

    void solveRec(vector<vector<int> > &ret, vector<int> &base, int cnt, vector<bool> &avail, vector<int> &num) {
        int n = num.size();
        if (cnt == n) {
            ret.push_back(base);
            return;
        }

        for (int i=0; i<n; ++i) {
            if (avail[i]) {
                avail[i] = false;
                base.push_back(num[i]);
                solveRec(ret, base, cnt+1, avail, num);
                base.pop_back();
                avail[i] = true;
            }
        }
    }
};
