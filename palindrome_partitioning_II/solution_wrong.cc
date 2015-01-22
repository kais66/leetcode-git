class Solution {
public:
    // backtracking causes TLE: because here without outputing all combinations, dp is faster than backtracking.
    // step 1: dp to log for every (i, j), if s[i..j] is a palindrome
    // step 2: dp to get min cut
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
            while (p >= 0 && q < n && s[p] == s[q]) {
                isPalin[p][q] = true; 
                p--;
                q++;
            }
        }

        vector<int> cut(n, INT_MAX);
        for (int i=0; i<n; ++i) {
            if (isPalin[0][i]) {
                cut[i] = 0;
                continue;
            }
            for (int j=0; j<i; ++j) {
                if (cut[j] != INT_MAX && isPalin[j+1][i]) {
                    cut[i] = min(cut[i], cut[j] + 1); 
                }
            }
        }
        return cut[n-1];
    }
};
