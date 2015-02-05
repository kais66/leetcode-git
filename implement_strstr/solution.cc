class Solution {
public:
    int strStr(char *haystack, char *needle) {
        char *h = haystack;
        if (*needle == '\0') return 0;
        int nlen = strlen(needle);
        while (*h != '\0') {
            char *n = needle;                
            char *temph = h;
            while (*n != '\0' && *h != '\0' && *n == *h) {
                ++n;
                ++h;
            }
            if (*n == '\0') return (h - haystack - nlen);
            if (*h != '\0') { 
                h = temph;
                h++;
            }
        }
        return -1;
    }
};
