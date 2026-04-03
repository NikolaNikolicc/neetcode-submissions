class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        visited = []

        for list in grid:
            visited.append([False]*len(list))

        maxSize = 0

        def dfs(r, c):
            ROWS, COLS = len(grid), len(grid[0])
            if min(r, c) < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0 or visited[r][c]:
                return 0

            visited[r][c] = True

            size = 1

            size += dfs(r - 1, c)
            size += dfs(r + 1, c)
            size += dfs(r, c + 1)
            size += dfs(r, c - 1)

            return size


        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1 and not visited[r][c]:
                    # currSize[0] = 0
                    currSize = dfs(r, c)
                    maxSize = max(maxSize, currSize)

        return maxSize