class Solution {
public:
    // note the API: isalnum(), tolower()... from <cctype> (ctype.h)
    bool isPalindrome(string s) {
        int n = s.size();                
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (i < n && !isalnum(s[i])) { ++i; }
            while (j >= 0 && !isalnum(s[j])) { --j; }
            if (i >= j) break;
            if (tolower(s[i]) != tolower(s[j])) { return false; }
            ++i;
            --j;
        }
        return true;
    }
};
