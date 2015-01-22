class Solution {
public:
    // this version gets Time Limit Exceeded error on leetcode, because it continues to check 4 neighbors regardless of wether the current node is visited before.
    // algo: http://fisherlei.blogspot.com/2013/03/leetcode-surrounded-regions-solution.html
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<n; ++i) {
            if (board[0][i] == 'O') bfs(board, 0, i); 
            if (m > 1 && board[m-1][i] == 'O') bfs(board, m-1, i); 
        }
        for (int i=0; i<m; ++i) {
            if (board[i][0] == 'O') bfs(board, i, 0); 
            if (n > 1 && board[i][n-1] == 'O') bfs(board, i, n-1); 
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'o') board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char> > &board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        queue<int> q;
        q.push(row*n + col);
        while (!q.empty()) {
            int val = q.front();
            q.pop();
            int r = val / n;
            int c = val % n;
            board[r][c] = 'o';
            
            if (r > 0 && board[r-1][c] == 'O') { q.push((r-1)*n + c); }
            if (c > 0 && board[r][c-1] == 'O') { q.push(r*n + c-1); }
            if (r <= m-2 && board[r+1][c] == 'O') { q.push((r+1)*n + c); }
            if (c <= n-2 && board[r][c+1] == 'O') { q.push(r*n + c+1); }
        }
    }
};


