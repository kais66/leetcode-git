class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> ways(n, 0);
        ways[0] = (s[0] >= '1' ? 1 : 0);
        if (n == 1) return ways[0];

        ways[1] = (s[1] >= '1' && ways[0] ? 1 : 0);
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) 
            ways[1] += 1;
        
        int num = 0;
        for (int i=2; i<n; ++i) {
            if (s[i] >= '1') 
                { ways[i] += ways[i-1]; }

            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                ways[i] += ways[i-2];
            }
        }

        return ways[n-1];
    }
};
