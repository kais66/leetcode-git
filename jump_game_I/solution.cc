class Solution {
public:
    // algo: use a var max to record currently the farthest ind it can go. 
    // if max < cur_ind, report failure; else, update max

    // dp[i]: farthest ind it can go at ind i
    // optimal substructure: dp[i] = max(dp[i-1], i+A[i])
    bool canJump(int A[], int n) {
        int maxl = 0;
        for (int i=0; i<n-1; ++i) { 
            if (maxl < i) return false;
            else {
                maxl = max(maxl, i+A[i]);
                if (maxl >= n-1) return true;
            }
        }
        return (maxl >= n-1);
    }
};
