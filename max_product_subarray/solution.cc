class Solution {
public:
    // dp[n]: max up to n. pos[n]: positive prod with A[n], neg[n]: negative prod with A[n]
    // dp[n] = max(A[n]*neg[n-1], A[n]*pos[n-1]).
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        int pos = 0;
        int neg = 0;
        if (A[0] > 0) pos = A[0];
        else neg = A[0];
        int maxp = A[0];

        for (int i=1; i<n; ++i) {
            if (A[i] > 0) {
                neg = (neg < 0 ? neg * A[i] : 0);
                pos = (pos > 0 ? pos * A[i] : A[i]);
                maxp = max(maxp, pos);
            } else if (A[i] < 0) {
                int prev_pos = pos;
                pos = (neg < 0 ? neg * A[i] : 0);
                maxp = max(maxp, pos);
                neg = (prev_pos > 0 ? prev_pos * A[i] : A[i]);
            } else {
                pos = 0;
                neg = 0;
            }
        }
        return maxp;            
    }
};

