class Solution {
public:
    // when both input are empty, should return 0
    // WRONG: the equation for calculating index is wrong. shouldn't have added 1, after while loop, h points to char after pattern
    int strStr(char *haystack, char *needle) {
        char *h = haystack;
        if (*h == '\0') return -1;
        int nlen = strlen(needle);
        while (*h != '\0') {
            char *n = needle;                
            while (*n != '\0' && *h != '\0' && *n == *h) {
                ++n;
                ++h;
            }
            if (*n == '\0') return (h - haystack - nlen + 1);
            if (*h != '\0') ++h;
        }
        return -1;
    }
};
