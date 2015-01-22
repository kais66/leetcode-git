class Solution {
public:
    // looking for a and b such that: x < A[a] = target = A[b] < y
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> nf(2, -1);
        vector<int> ret(2);

        int start = -1;
        int end = n;                
        // A[start] < target <= A[end]
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (A[mid] >= target) { end = mid; }
            else { start = mid; }
        }
        if (target != A[end]) return nf;
        ret[0] = end;

        start = -1;
        end = n;                
        // A[start] <= target < A[end]
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (A[mid] <= target) { start = mid; }
            else { end = mid; }
        }
        ret[1] = start;
        return ret;
    }
};
