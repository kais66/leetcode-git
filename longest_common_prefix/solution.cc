class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string ret = strs[0];          
        int len = ret.size();
        int num = strs.size();
        for (int i=0; i<len; ++i) {
            for (int j=1; j<num; ++j) {
                string &s = strs[j];
                if (i == s.size() || ret[i] != s[i]) { return ret.substr(0, i); } // if i==0, return empty string
            }
        }
        return ret;
    }
};
