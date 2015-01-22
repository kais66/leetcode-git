class Solution {
public:
    // http://fisherlei.blogspot.com/2012/12/leetcode-palindrome-number.html
    // cases: 1. 101101, dvs=100000. This is actually handled, no need to worry, because l will be 0, when x =110. 
    bool isPalindrome(int x) {
        if (x < 0) return false; // negative number is not palindrome, because it has a sign
        int dvs = 1; // divisor
        while (x / dvs >= 10) { dvs *= 10; };

        while (x > 0) {
            int l = x / dvs;
            int r = x % 10;
            if (l != r) return false;
            x = x % dvs / 10; // % is to remove MSB, /10 is to remove LSB.
            dvs /= 100; 
        }
        return true;
    }
};
