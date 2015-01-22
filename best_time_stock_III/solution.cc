class Solution {
public:
    // two pass
    // http://yucoding.blogspot.com/2012/12/leetcode-question-10-best-time-to-buy.html
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        // 1st pass, find max_prof for 0..up to i
        vector<int> pf(n, 0);
        int low = prices[0];                
        int cur_max = 0;
        for (int i=1; i<n; ++i) {
            pf[i] = max(prices[i] - low, cur_max); 
            if (pf[i] > cur_max)
                cur_max = pf[i];
            if (prices[i] < low) 
                low = prices[i];
        }

        // 2nd pass, find max_prof for i up to n-1
        int totpf = pf[n-1];
        int high = prices[n-1];
        cur_max = 0;
        for (int i=n-2; i>=1; --i) {
            int curpf = max(high - prices[i], cur_max); 
            if (curpf > cur_max) 
                cur_max = curpf;
            if (prices[i] > high)
                high = prices[i];

            int local_max = curpf + pf[i-1];
            if (totpf < local_max) 
                totpf = local_max;
        }
        return totpf;
    }
};
