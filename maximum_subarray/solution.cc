class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;

        int maxs = 0;
        int cur = 0;                
        for (int i=0; i<n; i++) {
            cur += A[i];
            if (maxs < cur) maxs = cur;
            if (cur < 0) cur = 0;
        }

        if (maxs == 0) {
            maxs = INT_MIN;
            for (int i=0; i<n; ++i) {
                if (maxs < A[i]) maxs = A[i];
            }
        }
        return maxs;
    }
};
