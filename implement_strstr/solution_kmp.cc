class Solution {
public:
    // implements KMP (not finished).
    int *strStr(char *haystack, char *needle) {
        int m = strlen(haystack);
        int n = strlen(needle);
        if (m == 0 || n == 0) return -1;
        vector<int> pi(n);
        computePref(needle, pi);
        int q = 0; 
        for (int i=0; i<m; ++i) {
            while (q > 0 && haystack[i] != needle[q+1]) { q = pi[q]; }
            if (haystack[i] == needle[q+1]) { ++q; }
            if (q+1 == n) return (i-n+1);
        }
        return -1;
    }

    void computePref(char *nd, vector<int> &pi) {
        int m = pi.size();
        pi[0] = 0;
        int k = 0;
        for (int i=1; i<m; ++i) {
            while (k > 0 && nd[k+1] != nd[i]) { k = pi[k]; }
            if (nd[k+1] == nd[i]) ++k;
            pi[i] = k;
        }
    }
};

