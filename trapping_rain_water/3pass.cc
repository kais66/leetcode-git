class Solution {
public:
    // 3-pass, with O(n) memory.
    int trap(int A[], int n) {
        if (n < 2) return 0;

        int lmax[n], rmax[n];
        lmax[0] = A[0];
        for (int i=1; i<n; ++i) {
            lmax[i] = max(lmax[i-1], A[i-1]);
        }

        rmax[n-1] = A[n-1];
        for (int i=n-2; i>=0; --i) {
            rmax[i] = max(rmax[i+1], A[i+1]);
        }

        int tot = 0;
        for (int i=1; i<n-1; ++i) {
            if (lmax[i] > A[i] && rmax[i] > A[i]) {
                tot += min(lmax[i], rmax[i]) - A[i];
            }
        }
        return tot;
    }
}
