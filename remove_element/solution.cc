class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int rem = 0;                
        for (int i=0; i<n; ++i) {
            if (A[i] == elem) { ++rem; }
            else {
                A[i-rem] = A[i];
            }
        }
        return n - rem;
    }
};
