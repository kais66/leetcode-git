class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > em;                
        if (numRows <= 0) return em;
        vector<vector<int> > ret(numRows, vector<int>(1, 1));
        
        for (int i=1; i<numRows; ++i) {
            vector<int> &last = ret[i-1];
            vector<int> &cur = ret[i];
            for (int j=1; j<i; ++j) {
                cur.push_back(last[j-1] + last[j]);
            }
            cur.push_back(1);
        }
        return ret;
    }
};
