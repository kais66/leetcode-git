class Solution {
public:
    // "((()))"
    // http://blog.csdn.net/worldwindjp/article/details/39460161
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) return 0;
        stack<int> sk; // elements are indices

        int start = 0; // e.g. in case of "()(())", need to keep track of the global start, index 0.
        int maxl = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') {
                sk.push(i);
            } else {
                if (sk.empty()) {
                    start = i + 1; // because no way it can form valid paren by including this s[i]
                    continue;
                }
                
                sk.pop();
                int curl = (sk.empty() ? i - start + 1 : i - (sk.top()+1) + 1); // if not empty, then there's un-matched left paren
                maxl = max(maxl, curl);
            }
        }
        return maxl;
    }
};
