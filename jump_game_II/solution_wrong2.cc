class Solution {
public:
    // observation: the first time a ind is discovered to be reachable, its num_jump is incremented.

    int jump(int A[], int n) {
        int maxl = 0;
        int minj = 0; // min jump
        for (int i=0; i<n-1; ++i) { // note loop should stop at i==n-2
            if (maxl < i) { return -1; }
            else {
                if (maxl < i + A[i]) {
                    maxl = i + A[i];
                    ++minj;
                    if (maxl >= n-1) return minj;
                }
            }
        }
        return (maxl >= n-1 ? minj : -1);
    }
};
