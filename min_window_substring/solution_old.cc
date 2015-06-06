class Solution {
public:
    // http://blog.csdn.net/linhuanmars/article/details/20343903
    // start points to a T char, which is a start point of a valid window substring
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

            // if c is a T char 
            sfreq[c]++;
            if (sfreq[c] <= tfreq[c]) { cnt++; }
            else {
                while (tfreq[S[start]] == 0) { ++start; }
                // move start pointer to pass the first occurance of c
                if (S[start] == c) { // should move start.
                    while (sfreq[S[start]] > tfreq[S[start]]) { // if new start pointing element with freq >tfreq, continue moving start
                        sfreq[S[start]]--;
                        ++start;
                        while (tfreq[S[start]] == 0) { ++start; }
                    }
                }
            }
            if (cnt == tn && i-start+1 < len) {
                len = i-start+1;
                ret = S.substr(start, i-start+1);
            }
        }
        return ret;
    }
};
