class Solution {
public:
    // DP solution is memory-intensive; just use recursion with pre-checking of whether breakable
    // ideone.com/53LMkr
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        if (s.empty()) {
            ret.push_back("");
        } else {
            bool is_breakable = false;
            int len = s.size();
            for (int i=len-1; i>=0; --i) {
                if (dict.find(s.substr(i, len-i)) != dict.end()) {
                    is_breakable = true;
                    break;
                }
            }
            if (!is_breakable) { return ret; }
            else { breakRec(s, 0, "", ret, dict); }
        }
        return ret;
    }

    void breakRec(string &s, int ind, string base, vector<string> &ret, unordered_set<string> &dict) {
        int n = s.size();
        if (ind == n) {
            ret.push_back(base);
            return;
        }

        for (int i=ind; i<n; ++i) {
            string subs = s.substr(ind, i-ind+1);
            if (dict.find(subs) != dict.end()) {
                if (ind > 0) { breakRec(s, i+1, base+" "+subs, ret, dict); }
                else { breakRec(s, i+1, base+subs, ret, dict); }
            }
        }
    }
};
