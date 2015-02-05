class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int dup = 0;
        for (int i=2; i<n; ++i) {
            if (A[i] == A[i-dup-1] && A[i] == A[i-dup-2]) {
                ++dup;
            } else {
                A[i-dup] = A[i];
            }
        }
        return n - dup;
    }
};
