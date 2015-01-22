class Solution {
public:
    // rule: no two queens share the same row, column, or diagonal
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n <= 0) return ret;

        vector<string> bd(n, string(n, '.'));
        solveRec(ret, bd, 0, n);
        return ret; 
    }

    void solveRec(vector<vector<string> > &ret, vector<string> &bd, int row, int n) {
        if (row == n) {
            ret.push_back(bd);
            return;
        }

        for (int i=0; i<n; ++i) {
            if (isValid(bd, row, i)) {
                bd[row][i] = 'Q';
                solveRec(ret, bd, row+1, n);
                bd[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string> &bd, int row, int col) {
        int n = bd.size(); 
        
        // test if this column is fine
        for (int i=0; i<row; ++i) {
            if (bd[i][col] == 'Q') return false;
        }

        // test left--up diagonal
        int i = row;
        int j = col;
        while (i>=0 && j>=0) {
            if (bd[i][j] == 'Q') return false;
            --i;
            --j;
        }

        i = row;
        j = col;
        while (i>=0 && j<n) {
            if (bd[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;    
    }
};

