class Solution {
public:
    // this solution causes overflow...
    // same logic as the insert position question
    // goal is to find y*y <= x < (y+1)^2
    int sqrt(int x) {
        if (x == 0 || x == 1) return x;
        int start = 1;
        int end = x/2 + 1; 

        // LI: start^2 <= x < end^2
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            long long m2 = mid * mid;
            if (m2 <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start;
    }
};
