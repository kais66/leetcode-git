class Solution {
public:
    // Just copied this code from the Internet
    //http://www.programcreek.com/2012/12/leetcode-regular-expression-matching-in-java/
    bool isMatch(const char *s, const char *p) {
        return isMatchRec(s, strlen(s), p, strlen(p));
    }

    bool isMatchRec(const char *s, int slen, const char *p, int plen) {
        if (plen == 0) { return slen == 0; }

        // p.size==1 is a special case; p[1]=='*' is also special and it depends on what p[0] is.
        if (plen == 1 || p[1] != '*') {
            if (slen < 1 || (p[0] != '.' && s[0] != p[0])) 
                { return false; }
            else { return isMatchRec(s+1, slen-1, p+1, plen-1); }
        } else {
            int i = 0;
            // if p[0..1] is ".*", or 0th char match, or p[0..1] matches 0 occurance of a char
            // because if these conditions are not met, we shouldn't enter this loop.
            while (i <= slen && (p[0] == '.' || p[0] == s[i] || i == 0)) {
                if (isMatchRec(s+i, slen-i, p+2, plen-2)) 
                    { return true; }
                i++;
            }
            return false;
        }
    }
};
