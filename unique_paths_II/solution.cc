class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        if (obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();                
        int n = obstacleGrid[0].size();                
        vector<vector<int> > &g = obstacleGrid;
        vector<vector<int> > path(m, vector<int>(n, 0));
        path[0][0] = g[0][0] ? 0 : 1;
        for (int i=1; i<n; ++i) 
            path[0][i] = g[0][i] ? 0 : path[0][i-1];
        for (int i=1; i<m; ++i) 
            path[i][0] = g[i][0] ? 0 : path[i-1][0];

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                path[i][j] = g[i][j] ? 0 : path[i-1][j] + path[i][j-1];
            }
        }

        return path[m-1][n-1];
    }
};
