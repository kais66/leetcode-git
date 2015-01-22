class Solution {
public:
    // idea: result should be num_left * num_right
    int numTrees(int n) {
        if (n <= 0) return 0;
        
        vector<int> num(n+1, 0); 
        num[0] = 1;
        num[1] = 1;
        
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<=i-1; ++j) { // 0 to i-1 nodes in a subtree
                num[i] += num[j] * num[i-1-j];
            }
        }

        return num[n];
    }
};
