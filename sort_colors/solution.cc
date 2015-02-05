class Solution {
public:
    void sortColors(int A[], int n) {
        int endr = -1; // end index of red
        int begb = n; // begin index of blue
        int i = 0;
        while (i < begb) {
            if (A[i] == 0) {  // move i and endr
                swap(A[endr+1], A[i]); // A[endr+1] should be 1, or A[i] itself if no 1 has been found
                ++endr;
                ++i;
            } else if (A[i] == 2) { // swap, only move begb
                swap(A[begb-1], A[i]); // A[begb-1] should be undiscovered element, 
                --begb;
            } else { ++i; } // only move i
        }
    }
};

