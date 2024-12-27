class Solution:
    def solve(self, x, y, row, col, dp, grid):
        if x == row and y == col:
            return grid[x][y]
        if x > row or y > col:
            return float('inf')
        if dp[x][y] != -1:
            return dp[x][y]
        
        down = grid[x][y] + self.solve(x+1, y, row, col, dp, grid)
        right = grid[x][y] + self.solve(x, y+1, row, col, dp, grid)

        dp[x][y] = min(down, right)
        return dp[x][y]

    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]

        return self.solve(0, 0, m-1, n-1, dp, grid)
        