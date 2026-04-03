class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        visited = []

        for list in grid:
            visited.append([False]*len(list))

        maxSize = [0]
        currSize = [0]

        def dfs(r, c):
            ROWS, COLS = len(grid), len(grid[0])
            if min(r, c) < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0 or visited[r][c]:
                return 0

            visited[r][c] = True

            currSize[0] += 1

            dfs(r - 1, c)
            dfs(r + 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)


        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1 and not visited[r][c]:
                    currSize[0] = 0
                    dfs(r, c)
                    maxSize[0] = max(maxSize[0], currSize[0])

        return maxSize[0]