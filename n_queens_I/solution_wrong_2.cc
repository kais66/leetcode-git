class Solution {
public:
    // http://blog.csdn.net/linhuanmars/article/details/20667175
    // rule: no two queens share the same row, column, or diagonal
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n < 1) return ret;  
        
        vector<int> board; // [2, 1, 0] meaning e.g., in first row, 3rd col is Q; 2nd row, 2nd col
        set<int> col;
        for (int i=0; i<n; ++i) col.insert(i);
        solveRec(ret, board, col, n);
        return ret;
    }

    void solveRec(vector<vector<string> > &ret, vector<int> &board, set<int> &col, int n) {
        int num = board.size();
        if (col.empty()) { // create solution
            if (num == n) {
                vector<string> base(n, string(n, '.'));
                for (int i=0; i<num; ++i) {
                    base[i][board[i]] = 'Q';
                }
                ret.push_back(base);
            }
            return;
        }

        for (int i : col) { // for each column. Now the considered point is (row, i)
            bool valid = true;
            // check diagonal validity
            for (int j=0; j<num; ++j) {
                if (abs(num-j) == abs(i-board[j])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                board.push_back(i);
                col.erase(i);
                solveRec(ret, board, col, n);
                col.insert(i);
                board.pop_back();
            }
        }
    }
};
