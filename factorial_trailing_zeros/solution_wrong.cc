class Solution {
public:
    // WRONG: can cause overflow, when n is extremely large, say INT_MAX; so use division instead 
    // algo: find out how many 5, 5^2, 5^3... that are no greater than n; for every instance, it adds an additional 0 to
    // the result
    int trailingZeroes(int n) {
        int base = 1;
        int ret = 0;
        while (base * 5 <= n) {
            base *= 5;
            ret += (n / base);
        }
        return ret;
    }
};
