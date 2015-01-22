class Solution {
public:
    // dp[i][j]: distance between word1[0..i] and word2[0..j]
    // dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1], dp[i-1][j-1] + 1or0 depending on if two letters equal
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        if (!l1 || !l2) return max(l1, l2);
        
        vector<vector<int> > dt(l1+1, vector<int>(l2+1, 0));
        for (int i=0; i<l2+1; ++i) dt[0][i] = i;
        for (int i=0; i<l1+1; ++i) dt[i][0] = i;

        for (int i=1; i<l1+1; ++i) {
            for (int j=1; j<l2+1; ++j) {
                int upleft = (word1[i-1] == word2[j-1]) ? dt[i-1][j-1] : dt[i-1][j-1] + 1;
                dt[i][j] = min(dt[i-1][j]+1, min(dt[i][j-1]+1, upleft));
            }
        }
        return dt[l1][l2];
    }
};
