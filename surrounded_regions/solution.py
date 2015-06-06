class Solution:
    # @param board, a 2D array
    # Capture all regions by modifying the input board in-place.
    # Do not return any value.
    def solve(self, board):
        if not board: return
        m, n = len(board), len(board[0])
        for i in range(m): board[i] = list(board[i])
            
        for i in range(m):
            if board[i][0] == 'O': self.backtrack(i, 0, board)
            if board[i][n-1] == 'O': self.backtrack(i, n-1, board)
        for i in range(n):
            if board[0][i] == 'O': self.backtrack(0, i, board)
            if board[m-1][i] == 'O': self.backtrack(m-1, i, board)
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O': board[i][j] = 'X'
                elif board[i][j] == 'o': board[i][j] = 'O'
        
        for i in range(m): board[i] = ''.join(board[i])
    
    def backtrack(self, row, col, board):
        m, n = len(board), len(board[0])
        if row<0 or row == m or col < 0 or col == n: return
        if board[row][col] == 'X' or board[row][col] == 'o': return
        board[row][col] = 'o'
        self.backtrack(row-1, col, board)
        self.backtrack(row, col-1, board)
        self.backtrack(row+1, col, board)
        self.backtrack(row, col+1, board)

if __name__ == '__main__':
    board = ['XOOO', 'XXXX']
    s = Solution()
    s.solve(board)
    print board
