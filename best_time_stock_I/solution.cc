class Solution {
public:
    // dp[0..n] = max(dp[0..n-1], (low-->price[n]))
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int low = prices[0]; 
        int pf = INT_MIN; 
        for (int i=1; i<n; ++i) {
            if (prices[i] - low > pf) 
                pf = prices[i] - low;
            if (prices[i] < low) low = prices[i]; 
        }
        return max(pf, 0);
    }
};
