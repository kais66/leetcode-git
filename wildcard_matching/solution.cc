class Solution {
public:
    // http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
    bool isMatch(const char *s, const char *p) {
        const char *pstar = NULL;
        const char *lasts = s;
        
        while (*s != '\0') {
            if (*p == '?' || *p == *s) {
                p++;
                s++;
                continue;
            }
            if (*p == '*') {
                pstar = p;
                lasts = s;
                p++;
                continue; // at the first time, we don't increment s pointer, because '*' matches 0 occurance as well
            }
            if (pstar) {
                p = pstar + 1;
                lasts++;
                s = lasts;
                continue;
            }
            return false;
        }
        while (*p == '*') p++;
        return *p == '\0';
    }
};
