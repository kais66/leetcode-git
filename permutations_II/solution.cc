class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        vector<int> base;
        int n = num.size();
        vector<bool> avail(n, true);
        sort(num.begin(), num.end());
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
                if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                    base.push_back(num[i]);
                    avail[i] = false;
                    solveRec(ret, base, cnt+1, avail, num);
                    avail[i] = true;
                    base.pop_back();    
                }
            }
        }
    }
};

