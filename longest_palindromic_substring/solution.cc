class Solution {
public:
    // this is the O(n^2) time, constant memory algo.
    // an linear time algo can be found: http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int maxl = 1;
        int start = 0; // start ind of max palin
        for (int i=0; i<n-1; ++i) {
            findPalin(s, i, i+1, maxl, start); 
            findPalin(s, i, i, maxl, start); 
        }
        return s.substr(start, maxl);
    }

    void findPalin(string &s, int left, int right, int &maxl, int &start) {
        int n = s.size();
        while (left>=0 && right<n && s[left] == s[right]) {
            --left;
            ++right;
        }
        int len = right - left - 1;
        if (len > maxl) {
            maxl = len;
            start = left + 1;
        }
    }
};
