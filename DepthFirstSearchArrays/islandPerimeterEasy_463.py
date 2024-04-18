class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        visited = set()

        def depthFirstSearch(i, j):
            if(i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or not grid[i][j]):
                return 1
            if (i, j) in visited:
                return 0
            visited.add((i, j))
            return depthFirstSearch(i+1, j) + depthFirstSearch(i, j+1) + depthFirstSearch(i-1, j) + depthFirstSearch(i, j-1)
            

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    return depthFirstSearch(i, j)