class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size(); 
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                visited[i][j] = true;
                if (board[i][j] == word[0] && searchRec(board, visited, i, j, word, 0)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }

    bool searchRec(vector<vector<char> > &board, vector<vector<bool> > &visited, int i, int j, string &word, int ind) {
        if (ind == word.size()-1) {
            return true;
        }
        if (i>0 && !visited[i-1][j] && board[i-1][j]==word[ind+1]) {
            visited[i-1][j] = true;
            if (searchRec(board, visited, i-1, j, word, ind+1)) return true;
            visited[i-1][j] = false;
        }
        if (j>0 && !visited[i][j-1] && board[i][j-1]==word[ind+1]) {
            visited[i][j-1] = true;
            if (searchRec(board, visited, i, j-1, word, ind+1)) return true;
            visited[i][j-1] = false;
        }
        if (i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==word[ind+1]) {
            visited[i+1][j] = true;
            if (searchRec(board, visited, i+1, j, word, ind+1)) return true;
            visited[i+1][j] = false;
        }
        if (j<board[0].size() && !visited[i][j+1] && board[i][j+1]==word[ind+1]) {
            visited[i][j+1] = true;
            if (searchRec(board, visited, i, j+1, word, ind+1)) return true;
            visited[i][j+1] = false;
        }
        return false;
    }
};
