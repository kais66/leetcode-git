class Solution {
public:
    // wrong: need to return double
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m + n) / 2; // index of array, mid+1 is index of kth
        if ((m+n) % 2 == 0) {
            return (kthLarge(A, m, B, n, mid) + kthLarge(A, m, B, n, mid+1))/2;
        } else {
            return kthLarge(A, m, B, n, mid + 1);
        }
    }

    // always make sure n >= m
    int kthLarge(int A[], int m, int B[], int n, int k) {
        //if (m > n) return kthLarge(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (n == 0) return A[k-1];
        if (k == 1) return min(A[0], B[0]);

        int rma = min(k/2, m); // num to remove from A
        int rmb = k - rma;
        if (A[rma-1] > B[rmb-1]) { // either A[rma] is the k-th, or a number after B[rmb-1] is.
            return kthLarge(A, m, B+rmb, n-rmb, k-rmb);
        } else { // either B[rmb] is the k-th, or a number after A[rma-1] is.
            return kthLarge(A+rma, m-rma, B, n, k-rma);
        }
    }
};
