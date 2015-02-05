class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = n;
        int dup = 0;
        for (int i=1; i<n; ++i) {
            if (A[i] == A[i-dup-1]) { ++dup; }
            else {
                A[i-dup] = A[i];
            }
        }
        return n-dup;
    }
};
