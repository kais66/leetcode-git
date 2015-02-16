class Solution {
public:
    // WRONG: the swap clause could cause infinite loop, if two values are equal
    int firstMissingPositive(int A[], int n) {
        int i = 0; 
        while (i < n) {
            if (A[i] <= 0 || A[i] > n || A[i] == i+1) {
                ++i; 
            } else {
                swap(A[i], A[A[i]-1]);
            } 
        }
        for (int i=0; i<n; ++i) {
            if (A[i] <= 0 || A[i] > n) return i+1;
        }
        return n+1;
    }
};
