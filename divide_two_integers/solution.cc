class Solution {
public:
    // terms: dividend = quotient * divisor + remainder, 0 <= remainder < divisor
    // basically to implement binary division. Think about how decimal division is really carried out, e.g. think when doing 987/2, we try 987/200, then remainder/20, then remainder/2.
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) { sign = -1; }
        // convert them to positive numbers 
        long long dd = (dividend > 0 ? dividend : 0 - (long long) dividend);
        long long ds = (divisor > 0 ? divisor : 0 - (long long) divisor);
        long long dspart = ds; // partial ds
        long long qt = 0;
        int steps = (dd >= ds ? 1 : 0);
        while ((dspart << 1) <= dd) {
            dspart = (dspart << 1);
            ++steps;
        }

        for (int i=0; i<steps; ++i) {
            qt = (qt << 1);
            if (dd >= dspart) {
                qt +=  1;
                dd -= dspart;
            }
            dspart = (dspart >> 1);
        }
        if (qt * sign > (long long) INT_MAX || qt*sign < (long long) INT_MIN) return INT_MAX;
        else return qt * sign;
    }
};
