class Solution {
public:
    // gives -1 when input is: [3,1], 1
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int start = 0;
        int end = n - 1;                

        // same termination condition as regular binary search: start <= end
        // what's the loop invariant of this?
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (A[mid] == target) return mid;
            if (A[mid] > A[start]) { // left side is sorted
                if (target < A[mid] && target >= A[start]) 
                    { end = mid - 1; }
                else { start = mid + 1; }
            } else { // A[mid] <= A[start] right side is sorted
                if (target <= A[end] && target > A[mid]) 
                    { start = mid + 1; }
                else { end = mid -1; }
            }
        }

        return -1;
    }
};
