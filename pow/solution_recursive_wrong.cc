class Solution {
public:
    // gets runtime error when input is:    1.00000, -2147483648 (need to handle n==INT_MIN, when -n becomes 0)
    double pow(double x, int n) {
        if (n == 0) return 1;
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
