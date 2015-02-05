class Solution {
public:
    // doesn't handle input e.g. "caae", "cae"
    // start points to a T char, which is a start point of a valid window substring
    string minWindow(string S, string T) {
        vector<int> tfreq(256, 0);                
        int tn = T.size();
        for (int i=0; i<tn; ++i) { tfreq[T[i]]++; };
        vector<int> sfreq(256, 0);
        int start = 0; // 
        int cnt = 0; // cnt is sum number of char present in sfreq
        int sn = S.size();
        int len = INT_MAX;
        string ret = "";
        for (int i=0; i<sn; ++i) {
            char c = S[i];
            if (tfreq[c] == 0) { continue; }

            // if c is a T char 
            // move start pointer to pass the first occurance of c
            while (tfreq[S[start]] == 0) { ++start; }
            while (sfreq[c] >= tfreq[c]) {
                if (sfreq[S[start]] > 0) { 
                    sfreq[S[start]]--;
                    --cnt;
                }
                ++start;
            }
            while (tfreq[S[start]] == 0) { ++start; }
            sfreq[c]++;
            cnt++;
            if (cnt == tn && i-start+1 < len) {
                len = i-start+1;
                ret = S.substr(start, i-start+1);
            }
        }
        return ret;
    }
};
