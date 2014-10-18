// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> cur(num);
        getPermRec(res, cur, 0, num.size());
        return res;
    }
    
    void getPermRec(vector<vector<int> > &res, vector<int> &cur, int ind, int size)
    {
        if (ind == size) {
            res.push_back(cur);
            return;
        }
        
        for (int i=ind; i<size; ++i) {
            // ensure that only one occurance for a unique number in digit "ind"
            bool is_dup = false;
            for (int j=ind; j<i; ++j) {
                if (cur[i] == cur[j]) {
                    is_dup = true;
                    break;
                }
            }
            if (is_dup) continue; 
            
            std::swap(cur[i], cur[ind]);
            getPermRec(res, cur, ind+1, size);
            std::swap(cur[i], cur[ind]);
        }
    }
};