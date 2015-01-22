class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sm(m, vector<int>(n, 0));                    
        sm[0][0] = grid[0][0];
        for (int i=1; i<n; ++i) sm[0][i] = grid[0][i] + sm[0][i-1];
        for (int i=1; i<m; ++i) sm[i][0] = grid[i][0] + sm[i-1][0];

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                sm[i][j] = min(sm[i-1][j], sm[i][j-1]) + grid[i][j];
            }
        }
        return sm[m-1][n-1];
    }
};
