class Solution {
public:
    // one pass: scan the array once, if val is not in hash, set(val, ind) for hash; else check if target-val is in hash.
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash; // value to index of numbers                
        int n = numbers.size();
        vector<int> ret(2, 0);
        for (int i=0; i<n; ++i) {
            int other = target - numbers[i];
            if (hash.find(other) != hash.end()) {
                ret[0] = hash[other] + 1;
                ret[1] = i + 1;
                return ret;
            }
            if (hash.find(numbers[i]) == hash.end()) { hash[numbers[i]] = i; }
        }
        return ret;
    }
};
