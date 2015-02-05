class Solution {
public:
    string convert(string s, int nRows) {
        int n = s.size();
        if (nRows == 1) return s;
        string ret(n, ' ');
        int ind = 0;
        for (int i=0; i<nRows; ++i) {
            int p = i;
            int prev = 2*i; // think how would it got here last time
            while (p < n) {
                ret[ind] = s[p];
                ++ind;
                if (i == 0 || i == nRows-1) { p += 2*nRows - 2; } // first and last rows need special treatment
                else {
                    p += (2*nRows - 2 - prev);
                    prev = 2*nRows - 2 - prev; 
                }
            }
        }
        return ret;
    }
};
