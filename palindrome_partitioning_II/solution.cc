class Solution {
public:
    // step 1: dp to log for every (i, j), if s[i..j] is a palindrome
    // step 2: backtracking to output all combinations 
    int minCut(string s) {
        if (s.empty()) return 0;
        int num = INT_MAX;
        
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

        vector<int> cut(n, INT_MAX);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                
            }
        }
        vector<string> base;
        solveRec(num, 0, isPalin, 0, s);
        return num;
    }

    void solveRec(int &num, int base_num, vector<vector<bool> > &isPalin, int ind, string &s) {
        int n = isPalin.size();
        if (ind == n) {
            if (base_num < num) num = base_num;
            return;
        }
        for (int i=ind; i<n; ++i) {
            if (isPalin[ind][i]) {
                solveRec(num, base_num+1, isPalin, i+1, s);
            }
        }
    }
};
