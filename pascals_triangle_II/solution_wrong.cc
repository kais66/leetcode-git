class Solution {
public:
    // WRONG: note for k==3, should return [1,3,3,1]
    // easy, the subtlty is in the bounds of for loops' ranges
    vector<int> getRow(int rowIndex) {
        vector<int> em;
        if (rowIndex <= 0) return em;                
        vector<int> ret(rowIndex, 1);
        for (int i=3; i<=rowIndex; ++i) {
            for (int j=i-2; j>=1; --j) { // because ret[i-1] will always be 1
                ret[j] = ret[j] + ret[j-1];
            }
        }
        return ret;
    }
};
