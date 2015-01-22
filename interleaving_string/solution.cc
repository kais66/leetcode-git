class Solution {
public:
    // dp[m][n]: whether s3[0..m+n] is interleave of s1[0..m] and s2[0..n]
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l1 + l2 != l3) return false;
        if (!l1) return s2 == s3;
        if (!l2) return s1 == s3;           

        vector<vector<bool> > dp(l1+1, vector<bool>(l2+1, false));
        dp[1][0] = (s3[0] == s1[0]);
        dp[0][1] = (s3[0] == s2[0]);
        for (int i=1; i<l2; ++i) dp[0][i+1] = (dp[0][i] && s3[i] == s2[i]); 
        for (int i=1; i<l1; ++i) dp[i+1][0] = (dp[i][0] && s3[i] == s1[i]);

        for (int i=0; i<l1; ++i) {
            for (int j=0; j<l2; ++j) {
                if ((dp[i][j+1] && s3[i+j+1] == s1[i]) || (dp[i+1][j] && s3[i+j+1] == s2[j]))
                    dp[i+1][j+1] = true;
            }
        }
        return dp[l1][l2];
    }
};
