class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.ROWS, self.COLS = len(grid), len(grid[0])

        rotten = deque()
        fresh = 0
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if grid[r][c] == 2:
                    rotten.append((r, c))
                if grid[r][c] == 1:
                    fresh += 1

        dirs = [[-1, 0], [+1, 0], [0, -1], [0, +1]]
        time = 0
        if len(rotten):
            time -= 1
        while rotten:
            l = len(rotten)

            for i in range(l):
                r, c = rotten.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if min(nr, nc) >= 0 and nr < self.ROWS and nc < self.COLS and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh -= 1
                        rotten.append((nr, nc))
            time += 1

        return time if fresh == 0 else -1
