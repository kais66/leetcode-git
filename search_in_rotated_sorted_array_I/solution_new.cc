class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;

        // target <= A[end] or target >= A[start], A[start..end] is the range to search in
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (A[mid] > A[start]) { // left side is sorted
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else { start = mid; }
            } else {
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else { end = mid; }
            }
        }
        if (A[start] == target) return start;
        else if (A[end] == target) return end;
        else return -1;
    }
};
