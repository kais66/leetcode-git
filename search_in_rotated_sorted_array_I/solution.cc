class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int start = 0;
        int end = n - 1;                

        // same termination condition as regular binary search: start <= end
        // what's the loop invariant of this?
        // special case when mid == start
        // Note: when start+1==end, we always have: mid==start
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (A[mid] == target) return mid;
            if (A[mid] >= A[start]) { // left side is sorted. Note the =
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
