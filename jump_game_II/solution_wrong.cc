class Solution {
public:
    // WRONG: what if only at ind n-1, it discovers n-1 is reachable (i.e. when array has a single element)
    // observation: the first time a ind is discovered to be reachable, its num_jump is incremented.
    int jump(int A[], int n) {
        int maxl = 0;
        int minj = 0; // min jump
        for (int i=0; i<n; ++i) {
            if (maxl < i) { return -1; }
            else {
                if (maxl < i + A[i]) {
                    maxl = i + A[i];
                    ++minj;
                    if (maxl >= n-1) return minj;
                }
            }
        }
        return minj;
    }
};
