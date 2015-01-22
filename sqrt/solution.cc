class Solution {
public:
    // http://yucoding.blogspot.com/2013/03/leetcode-question-102-sqrtx.html
    // same logic as the insert position question
    // goal is to find y*y <= x < (y+1)^2
    int sqrt(int x) {
        if (x == 0 || x == 1) return x;
        int start = 1;
        int end = x/2 + 1;

        // LI: start^2 <= x < end^2
        while (start + 1 < end) {
            long mid = (start + end) / 2; //** to perform multiplication, mid has to be long (memorize)
            long m2 = mid * mid; // **
            if (m2 <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start;
    }

    // side note: 8-bit has 256 (2^8) representable values. 2^7-1 positive, 2^7 negative, and 0.
};
