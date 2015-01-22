class Solution {
public:
    // should use long long
    int reverse(int x) {
        long xl = (long) x;
        bool neg = (xl < 0 ? true : false);                
        xl = abs(xl);
        long ret = 0;
        while (xl > 0) {
            int d = xl % 10;
            ret = ret * 10 + d;
            xl /= 10;
        }
        if (ret > (long) INT_MAX) return 0;
        return (neg ? -(int)ret : (int) ret);
    }
};
