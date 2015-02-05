class Solution {
public:
    // copy from end to start
    void merge(int A[], int m, int B[], int n) {
        int i = m + n - 1;                
        int ap = m - 1;
        int bp = n - 1;
        while (ap >= 0 && bp >= 0) {
            if (A[ap] > B[bp]) { A[i--] = A[ap--]; }
            else { A[i--] = B[bp--]; }
        }
        while (ap >= 0) { A[i--] = A[ap--]; }
        while (bp >= 0) { A[i--] = B[bp--]; }
    }
};
