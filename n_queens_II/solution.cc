class Solution {
public:
    // rule: no two queens share the same row, column, or diagonal
    int totalNQueens(int n) {
        int num = 0;
        if (n <= 0) return num;

        vector<string> bd(n, string(n, '.'));
        solveRec(bd, 0, num, n);
        return num; 
    }

    void solveRec(vector<string> &bd, int row, int &num, int n) {
        if (row == n) {
            num++;
            return;
        }

        for (int i=0; i<n; ++i) {
            if (isValid(bd, row, i)) {
                bd[row][i] = 'Q';
                solveRec(bd, row+1, num, n);
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

