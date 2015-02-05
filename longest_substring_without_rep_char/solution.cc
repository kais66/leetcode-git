class Solution {
public:
    // cleanCode book;
    // http://fisherlei.blogspot.com/2012/12/leetcode-longest-substring-without.html
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<bool> exist(256, false);
        int start = 0;
        int n = s.size();
        int ret = 0;
        for (int i=0; i<n; ++i) {
            char c = s[i];
            while (exist[c]) { // if previously this char is found, need to move start to cancel the first occurance of s[i] character
                exist[s[start]] = false;
                ++start;
            }
            exist[s[i]] = true;
            ret = max(ret, i-start+1);
        }
        return ret;
    }
};


