class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        dirs = [(-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0)]
        queue = deque()
        visited = set()

        ROWS, COLS = len(grid), len(grid[0])

        if not grid[0][0]:
            queue.append((0, 0, 1))
            visited.add((0, 0))

        while queue:
            qlen = len(queue)
            for _ in range(qlen):
                r, c, l = queue.popleft()

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if min(nr, nc) >= 0 and nr < ROWS and nc < COLS and not grid[nr][nc] and (nr, nc) not in visited:
                        queue.append((nr, nc, l + 1))
                        visited.add((nr, nc))
                        if nr == ROWS - 1 and nc == COLS - 1:
                            return l + 1
        return -1