class Solution {
public:
    // easy, the subtlty is in the bounds of for loops' ranges
    vector<int> getRow(int rowIndex) {
        vector<int> em;
        if (rowIndex < 0) return em;                
        int num = rowIndex + 1;
        vector<int> ret(num, 1);
        for (int i=3; i<=num; ++i) {
            for (int j=i-2; j>=1; --j) { // because ret[i-1] will always be 1
                ret[j] = ret[j] + ret[j-1]; // the trick is doing this backwards, so a second array is not needed
            }
        }
        return ret;
    }
};
