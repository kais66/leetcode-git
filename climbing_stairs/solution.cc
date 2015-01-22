class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        
        vector<int> num(n + 1, 0);                
        num[1] = 1;
        num[2] = 2;
        for (int i=3; i<=n; ++i) {
            num[i] = num[i-1] + num[i-2];
        }
        return num[n];
    }
};
