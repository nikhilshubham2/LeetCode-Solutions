class Solution:
    def valid(self, board, row, col, c):
        for i in range(9):
            if board[row][i] == c:
                return False
            if board[i][col] == c:
                return False
            if board[3*(row//3) + i//3][3*(col//3) + i%3] == c:
                return False
        return True
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    c = board[i][j]
                    board[i][j] = '.'
                    if not self.valid(board, i, j, c):
                        return False
        return True
        