class Solution {
public:
    // http://yucoding.blogspot.com/2014/10/single-number-ii.html
    int singleNumber(int A[], int n) {
        int one = 0;
        int two = 0; // bit is 1 is two numbers have that bit as 1
        int thr = 0;                
        for (int i=0; i<n; ++i) {
            two = two | (one & A[i]); // two is orig two, incorporating (one & A[i])
            one = one ^ A[i]; // one is got from XOR operation.
            thr = one & two; // if a bit both appear in one, and two, then it's also in three
            one = one & (~thr); // for a '1' in three, reset corresponding bit in one and two
            two = two & (~thr);
        }
        return one;
    }
};
