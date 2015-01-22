class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n <= 0) return ret;
        
        string base(n * 2, '(');
        solveRec(ret, base, 0, 0); 
        return ret;
    }

    void solveRec(vector<string> &ret, string &base, int l, int r) {
        int n = base.size() / 2;
        if (l == n && r == n) {
            ret.push_back(base);
            return;
        }

        if (r < n && r < l) {
            base[l+r] = ')';
            solveRec(ret, base, l, r+1);
        }
        if (l < n) {
            base[l+r] = '(';
            solveRec(ret, base, l+1, r);
        }
    }
};
