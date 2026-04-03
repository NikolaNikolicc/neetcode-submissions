class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        dirs = [1, 0, -1, 0, 1]
        def dfs(r, c):
            if min(r, c) < 0 or r >= ROWS or c >= COLS or not grid[r][c]:
                return 0

            grid[r][c] = 0
            cnt = 1
            for dir in range(4):
                cnt += dfs(r + dirs[dir], c + dirs[dir + 1])
            return cnt

        maxCnt, currCnt = 0, 0
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c]:
                    currCnt = dfs(r, c)
                    maxCnt = max(maxCnt, currCnt)
        return maxCnt

