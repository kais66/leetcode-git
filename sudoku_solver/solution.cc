class Solution {
public:
    //http://www.geeksforgeeks.org/backtracking-set-7-suduku/
    void solveSudoku(vector<vector<char> > &board) {
        solveRec(board, 0, 0);
    }

    bool solveRec(vector<vector<char> > &bd, int r, int c) {
        if (r == 9 && c == 0) {
            return true;
        }
        
        bool ret = false;
        if (bd[r][c] == '.') {
            for (int i=1; i<=9; ++i) {
                if (isValid(bd, r, c, '0'+i)) {
                    bd[r][c] = '0' + i;
                    if (c == 8) ret = solveRec(bd, r+1, 0);
                    else ret = solveRec(bd, r, c+1);
                    if (ret) return true; // if true, need to keep the modified board
                    bd[r][c] = '.';
                }
            }
        } else {
            if (c == 8) ret = solveRec(bd, r+1, 0);
            else ret = solveRec(bd, r, c+1);
        }
        return ret;
    }

    bool isValid(vector<vector<char> > &bd, int r, int c, char val) {
        for (int i=0; i<9; ++i) {
            if (bd[r][i] == val) return false;
        }
        for (int i=0; i<9; ++i) {
            if (bd[i][c] == val) return false;
        }
        
        for (int i=r/3*3; i<r/3*3 + 3; ++i) {
            for (int j=c/3*3; j<c/3*3 + 3; ++j) {
                if (bd[i][j] == val) return false;
            }
        }
        return true;
    }
};
