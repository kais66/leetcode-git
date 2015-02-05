class Solution {
public:
    // WRONG:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n - 1;                
        int ap = m - 1;
        int bp = n - 1;
        while (ap >= 0 || bp >= 0) {
            if (ap < 0 || A[ap] < B[bp]) { // bp could be <0 here
                A[i] = B[bp]; 
                --bp;
            } else {
                A[i] = A[ap];
                --ap;
            } 
            --i;
        }
    }
};
