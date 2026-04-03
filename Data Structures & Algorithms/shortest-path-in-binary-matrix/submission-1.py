from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        steps = [
            [-1, 0], [-1, -1],
            [0, -1], [1, -1],
            [1, 0], [1, 1],
            [0, 1], [0, -1]
        ]

        queue = deque()
        visited = set()

        if not grid[0][0]:
            queue.append((0, 0, 1))
            visited = set()

        ROWS, COLS = len(grid), len(grid[0])
        while queue:

            for i in range(len(queue)):
                r, c, w = queue.popleft()

                if r == ROWS - 1 and c == COLS - 1:
                    return w

                for dr, dc in steps:
                    nr, nc = r + dr, c + dc

                    if (min(nr, nc) < 0 or nr >= ROWS or nc >= COLS or (nr, nc) in visited or \
                    grid[nr][nc] == 1):
                        continue

                    queue.append((nr, nc, w + 1))
                    visited.add((nr, nc))

        return -1