class Solution(object):
    def func(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        visited = set()

        def cannotVisit(i, j):
            return (i < 0 or i >= len(grid)) or (j < 0 or j >= len(grid[0])) or (grid[i][j] == "0") or ((i, j) in visited) 

        def depthFirstSearch(i, j):
            if cannotVisit(i, j):
                return 0

            visited.add((i, j))

            return 1 + depthFirstSearch(i+1, j) + depthFirstSearch(i, j+1) + depthFirstSearch(i-1, j) + depthFirstSearch(i, j-1)  


        count = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if( ''' Logic ''' and not cannotVisit(i,j)):
                    if(depthFirstSearch(i, j)):
                        count += 1
        return count