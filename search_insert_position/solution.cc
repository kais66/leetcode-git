class Solution {
public:
    // http://fihopzz.blogspot.com/search?updated-min=2013-01-01T00:00:00-06:00&updated-max=2014-01-01T00:00:00-06:00&max-results=1
    int searchInsert(int A[], int n, int target) {
        if (n <= 0) return 0;                
        int start = -1; // **
        int end = n; // **

        // LI: (A[start] < target && target <= A[end]) {
        while (start + 1 < end) { // **
            int mid = (start + end) / 2;
            if (target <= A[mid]) { // **
                end = mid;
            } else {
                start = mid;
            }
        }
        return end;
    }
};
