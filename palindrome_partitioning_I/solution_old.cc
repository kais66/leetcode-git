class Solution {
public:
    // memory limit exceeded
    // step 1: dp to log for every (i, j), if s[i..j] is a palindrome
    // step 2: backtracking to output all combinations 
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if (s.empty()) return ret;
        
        int n = s.size();
        vector<vector<bool> > isPalin(n, vector<bool>(n, false)); 
        for (int i=0; i<n; ++i) {
            isPalin[i][i] = true;
            int p = i - 1;
            int q = i + 1;
            while (p >= 0 && q < n && s[p] == s[q]) {
                isPalin[p][q] = true; 
                p--;
                q++;
            }
        }
        for (int i=0; i<n-1; ++i) {
            isPalin[i][i+1] = (s[i] == s[i+1]);
            int p = i;
            int q = i + 1;
            while (p >= 0 && q < n && s[q] == s[q]) {
                isPalin[p][q] = true; 
                p--;
                q++;
            }
        }
        vector<string> base;
        solveRec(ret, base, isPalin, 0, s);
        return ret;
    }

    void solveRec(vector<vector<string> > &ret, vector<string> &base, vector<vector<bool> > &isPalin, int ind, string &s) {
        int n = isPalin.size();
        if (ind == n) {
            ret.push_back(base);
            return;
        }
        for (int i=ind; i<n; ++i) {
            if (isPalin[ind][i]) {
                string subs = s.substr(ind, i-ind+1);
                base.push_back(subs);
                solveRec(ret, base, isPalin, i+1, s);
                base.pop_back();
            }
        }
    }
};
