class Solution {
public:
    // basic idea is sort the string
    // an improvement to make this a one-pass algo is using map and set an init value of index
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        unordered_map<string, int> hash;
        int n = strs.size();
        for (int i=0; i<n; ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (hash.find(temp) == hash.end()) { hash[temp] = i; }
            else {
                if (hash[temp] != -1) {
                    ret.push_back(strs[hash[temp]]); 
                    hash[temp] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};
