class Solution {
public:
    int singleNumber(int A[], int n) {
        int p = 0;
        for (int i=0; i<n; ++i) {
            p = p ^ A[i];    
        }
        return p;
    }
};
