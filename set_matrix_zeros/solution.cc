class Solution {
public:
    // http://yucoding.blogspot.com/2013/04/leetcode-question-97-set-matrix-zeros.html
    // using first row, and first column to log whether the corresponding column and row needs to be set, respectively.
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;                
        int m = matrix.size();
        int n = matrix[0].size();
        bool czero = false;
        bool rzero = false;
        for (int i=0; i<m; ++i) {
            if (matrix[i][0] == 0) {
                czero = true;
                break;
            }
        }
        for (int i=0; i<n; ++i) {
            if (matrix[0][i] == 0) {
                rzero = true;
                break;
            }
        }

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i=1; i<m; ++i) {
            if (matrix[i][0] == 0) set(matrix, false, i);
        }
        for (int i=1; i<n; ++i) {
            if (matrix[0][i] == 0) set(matrix, true, i);
        }
        if (rzero) set(matrix, false, 0);
        if (czero) set(matrix, true, 0);
    }

    void set(vector<vector<int> > &matrix, bool isCol, int ind) {
        if (isCol) {
            for (int i=0; i<matrix.size(); ++i) { matrix[i][ind] = 0; }
        } else {
            for (int i=0; i<matrix[0].size(); ++i) { matrix[ind][i] = 0; }
        }
    }    
};
