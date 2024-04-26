class Solution:
    def minFallingPathSum(self, grid):
        n = len(grid)
        memo = [[float('inf')] * n for _ in range(n)]
        minCol = None
        secondMinCol = None
        
        for col in range(n):
            memo[n - 1][col] = grid[n - 1][col]
            if minCol is None or memo[n - 1][col] <= memo[n - 1][minCol]:
                secondMinCol = minCol
                minCol = col
            elif secondMinCol is None or memo[n - 1][col] <= memo[n - 1][secondMinCol]:
                secondMinCol = col
            
        for row in range(n - 2, -1, -1):
            currentMinCol = None
            currentSecondMinCol = None

            for col in range(n):
                if col != minCol:
                    memo[row][col] = grid[row][col] + memo[row + 1][minCol]
                else:
                    memo[row][col] = grid[row][col] + memo[row + 1][secondMinCol]
                
                if currentMinCol is None or memo[row][col] <= memo[row][currentMinCol]:
                    currentSecondMinCol = currentMinCol
                    currentMinCol = col
                elif currentSecondMinCol is None or memo[row][col] <= memo[row][currentSecondMinCol]:
                    currentSecondMinCol = col
            
            minCol = currentMinCol
            secondMinCol = currentSecondMinCol
        
        return memo[0][minCol]
