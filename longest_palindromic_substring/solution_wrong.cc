class Solution {
public:
    // Note this technique is wrong
    // dp[n]: length of longest palin ending at s[n]
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        vector<int> dp(n, 1); 
        int maxl = 1;
        int maxind = 0;
        for (int i=1; i<n; ++i) {
            if (dp[i-1] == 1) {
                if (s[i] == s[i-1]) dp[i] = 2;
                if (i-2 >= 0 && s[i] == s[i-2]) dp[i] = 3;
            } else {
                int ind = i-1-dp[i-1];
                if (s[i] == s[ind]) dp[i] = dp[i-1] + 2;
            }
            if (dp[i] > maxl) {
                maxl = dp[i];
                maxind = i;
            }
        }
        int ind = maxind - maxl + 1;
        return s.substr(ind, maxl);
    }
};
