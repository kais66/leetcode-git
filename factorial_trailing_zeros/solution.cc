class Solution {
public:
    // algo: find out how many 5, 5^2, 5^3... that are no greater than n; for every instance, it adds an additional 0 to
    // the result
    int trailingZeroes(int n) {
        if (n < 0) return 0;
        int base = 1;
        int ret = 0;
        while (base <= INT_MAX/5 && base * 5 <= n) { // first condition is for detecting overflow
            base *= 5;
            ret += (n / base);
        }
        return ret;
    }
};
