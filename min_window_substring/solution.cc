class Solution {
public:
    // http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
    // algo: two hash tables, two pointers. Right pointer always stops at a valid char which belongs to the pattern. When moving right pointer, update cnt (number of essential chars seen so far, not exceeding per char count) and sfreq (number of valid chars seen). For every right pointer location, if cnt is equal to the number of chars in the pattern, we advance left pointer as far right as possible while maintaining the constraint.
    string minWindow(string S, string T) {
        vector<int> tfreq(256, 0);                
        int tn = T.size();
        for (int i=0; i<tn; ++i) { tfreq[T[i]]++; };
        vector<int> sfreq(256, 0);
        int start = 0; // 
        while (tfreq[S[start]] == 0) { ++start; }
        int cnt = 0; // cnt is sum number of char present in sfreq
        int sn = S.size();
        int len = INT_MAX;
        string ret = "";
        for (int i=0; i<sn; ++i) {
            char c = S[i];
            if (tfreq[c] == 0) { continue; }

            sfreq[c]++;
            if (sfreq[c] <= tfreq[c]) { cnt++; } // won't increment if we've got more than enought this char.
            if (cnt == tn) {
                char leftc = S[start];
                // while (tfreq[leftc] == 0 || sfreq[leftc] > tfreq[leftc]) { 
                while (tfreq[leftc] == 0 || (sfreq[c] > tfreq[c] && leftc == c)) { 
                    if (sfreq[leftc] > 0) { --sfreq[leftc]; }
                    ++start; 
                    leftc = S[start];
                }
                if (i-start+1 < len) {
                    len = i-start+1;
                    ret = S.substr(start, i-start+1);
                }
            }
        }
        return ret;
    }
};
