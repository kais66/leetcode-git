class Solution {
public:
    // http://blog.csdn.net/abcbc/article/details/8978146
    // dp[i][j]: num of distinct subseq T[0..i] existing in S[0..j] 
    // dp[i][j] = dp[i][j-1] + (T[i]==S[j] ? dp[i-1][j-1] : 0)
    int numDistinct(string S, string T) {
        int sl = S.size();
        int tl = T.size();
        //if (!sl || !tl) return max(sl, tl);
        if (!sl) return 0;
        if (!tl) return sl;

        vector<vector<int> > dp(tl, vector<int>(sl, 0)); 
        dp[0][0] = S[0] == T[0] ? 1 : 0;
        //for (int i=1; i<sl; ++i) dp[0][i] = dp[0][i-1] + (T[0]==S[i]) ? 1 : 0;
        for (int i=1; i<sl; ++i) dp[0][i] = dp[0][i-1] + (T[0]==S[i] ? 1 : 0);

        for (int i=1; i<tl; ++i) {
            for (int j=1; j<sl; ++j) {
                dp[i][j] = dp[i][j-1] + (T[i] == S[j] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[tl-1][sl-1];
    }
};
