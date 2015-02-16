class Solution {
public:
    // Key is the if condition before swap
    int firstMissingPositive(int A[], int n) {
        int i = 0; 
        while (i < n) {
            if (A[i] <= 0 || A[i] > n || A[i] == i+1) {
                ++i; 
            } else {
                if (A[i] == A[A[i]-1]) A[i] = -1;
                else swap(A[i], A[A[i]-1]); // always think about what should happen if two elements to be swapped are the same
            } 
        }
        for (int i=0; i<n; ++i) {
            if (A[i] <= 0 || A[i] > n) return i+1;
        }
        return n+1;
    }
};
