class Solution {
public:
    // step 1: dp to log for every (i, j), if s[i..j] is a palindrome
    // step 2: backtracking to output all combinations 
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if (s.empty()) return ret;
        
        vector<string> base;
        solveRec(ret, base, 0, s);
        return ret;
    }

    void solveRec(vector<vector<string> > &ret, vector<string> &base, int ind, string &s) {
        int n = s.size();
        if (ind == n) {
            ret.push_back(base);
            return;
        }
        for (int i=ind; i<n; ++i) {
            if (isPalin(s, ind, i)) {
                string subs = s.substr(ind, i-ind+1);
                base.push_back(subs);
                solveRec(ret, base, i+1, s);
                base.pop_back();
            }
        }
    }

    bool isPalin(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
