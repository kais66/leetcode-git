class Solution {
public:
    // https://oj.leetcode.com/discuss/8092/my-dp-o-n-solution-without-using-stack
    // dp[0..i]: length of longest valid paren ending at s[i]
    // dp method is easier to understand compared with stack one
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0);
        dp[1] = (s[0] == '(' && s[1] == ')') ? 2 : 0;
        int ret = dp[1];

        for (int i=2; i<n; ++i) {
            if (s[i] == '(') continue;

            int l1 = 0;
            int l2 = 0;
            if (s[i-1] == '(') {
                l2 = dp[i-2] + 2;
            } else { // ')'
                int ind = i - 1 - dp[i-1];
                l1 = (ind >= 0 && s[ind] == '(') ? dp[i-1] + 2 : 0;
                if (l1 > 0 && ind-1 >= 0) l1 += dp[ind-1]; // this line is easy to forget,  think "()(())"
            }
            dp[i] = max(l1, l2);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
