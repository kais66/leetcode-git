class Solution {
public:
    // 2-pass, with O(n) memory.
    // Key observations: 1. for each index, to calculate how much water the bar of this index can hold, 
    // we need to look both left (lmax)
    // and right (rmax) to find what's the highest boundary in each direction. The amount of water to be held: 
    // max(0, min(lmax, rmax)-A[i])
    // 2. lmax[] can be built by a single linear scan. (lmax[i] is max{A[0..i-1]}) 
    int trap(int A[], int n) {
        if (n < 2) return 0;

        int lmax[n];
        lmax[0] = A[0];
        for (int i=1; i<n; ++i) {
            lmax[i] = max(lmax[i-1], A[i-1]);
        }

        int rmax = A[n-1];
        int tot = 0;
        for (int i=n-2; i>=1; --i) {
            rmax = max(rmax, A[i+1]);
            if (lmax[i] > A[i] && rmax > A[i]) {
                tot += min(lmax[i], rmax) - A[i];
            }
        }
        return tot;
    }
}
