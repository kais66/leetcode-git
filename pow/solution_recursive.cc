class Solution {
public:
    // http://www.programcreek.com/2012/12/leetcode-powx-n/
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) {
            int n2 = n/2;
            double p2 = 1.0 / solveRec(x, -n2);
            return p2 * p2;
        }
        return (n > 0 ? solveRec(x, n) : 1/solveRec(x, -n));
    }

    // n is guaranteed to be positive
    double solveRec(double x, int n) {
        if (n == 1) return x;

        // n > 1 case
        double half = solveRec(x, n/2);
        return (n % 2 == 0 ? half * half : half * half * x);
    }
};
