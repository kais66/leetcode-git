class Solution {
public:
    // terms: dividend = quotient * divisor + remainder, 0 <= remainder < divisor
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1; 
        }
        // convert them to positive numbers 
        long long dd = (dividend > 0 ? dividend : 0 - (long long) dividend);
        long long ds = (divisor > 0 ? divisor : 0 - (long long) divisor);
        long long dspart = ds; // partial ds
        long long qt = 0;
        int steps = 0;
        while (dspart << 1 <= dd) {
            dspart = (dspart << 1);
            ++steps;
        }

        while (dd >= ds) { // WRONG: imagine 1000 / 10, then first dspart is 1000, then dd will become 0. But we do want the loop to continue
            qt = (qt << 1);
            if (dd >= dspart) {
                qt +=  1;
                dd -= dspart;
            }
            dspart = (dspart >> 1);
        }
    }
};
