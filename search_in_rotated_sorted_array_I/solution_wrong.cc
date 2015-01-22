class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int start = 0;
        int end = n - 1;                

        // same termination condition as regular binary search
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (A[mid] == target) return mid;
            if (A[mid] < target) {
                if (A[start] < A[mid]) { start = mid + 1; }
                else  
            } else { // A[mid] > target

            }
        }
    }
};
