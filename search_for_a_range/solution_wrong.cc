class Solution {
public:
    // gives wrong answer of [1,0] for input: [2,2], 2
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> nf(2, -1);
        vector<int> ret;

        int start = -1;
        int end = n;                
        // A[start] <= target < A[end]
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (A[mid] <= target) { start = mid; }
            else { end = mid; }
        }
        if (target != A[start]) return nf;
        else ret.push_back(start);

        start = -1;
        end = n;                
        // A[start] < target <= A[end]
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (A[mid] >= target) { end = mid; }
            else { start = mid; }
        }
        if (target != A[end]) return nf;
        ret.push_back(end);
        return ret;
    }
};
