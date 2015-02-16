class Solution {
public:
    // http://blog.csdn.net/havenoidea/article/details/11853301
    //dp[n]: min num of steps to reach n
    //dp[n] = min for all i { dp[n-i], n-i can reach n} 
    // further optimization can remove the use of additional memory
    int jump(int A[], int n) {
        if (n <= 0) return -1;
        int maxl = 0;
        vector<int> dp(n, 0);
        for (int i=0; i<n-1; ++i) { // note loop should stop at i==n-2
            if (maxl < i) { return -1; }

            if (maxl < i + A[i]) {
                for (int j=maxl+1; j<=min(i+A[i], n-1); ++j) {
                    dp[j] = dp[i] + 1;
                }
                maxl = i + A[i];
            }
        }
        return (maxl >= n-1 ? dp[n-1] : -1);
    }
};
