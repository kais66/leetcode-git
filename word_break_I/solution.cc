class Solution {
public:
    // http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
    // O(n^2) time
    // algo: for i in [0..n-1], test if s[0..i] is breakable: if itself is in dictionary (new test to be done), or if it can be broken into multiple words (from previous iterations); if it's breakable, check for j in [i+1, n], if s[i+1, j] exists in dictionary.
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) return true;
        int n = s.size();
        vector<bool> brkb(n, false); // brkb[i]=true if s[0..i] is breakable

        for (int i=0; i<n; ++i) {
            string subs = s.substr(0, i+1);
            if (dict.find(subs) != dict.end()) {
                brkb[i] = true;
            }
            if (brkb[i]) {
                for (int j=i+1; j<n; ++j) {
                    string subs2 = s.substr(i+1, j-i);
                    if (dict.find(subs2) != dict.end()) {
                        brkb[j] = true;
                    }
                }
            }
        }

        return brkb[n-1];
    }
};
