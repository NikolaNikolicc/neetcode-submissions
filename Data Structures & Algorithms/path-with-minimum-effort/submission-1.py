class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        if len(heights) == 0 or len(heights[0]) == 0:
            return -1
        
        minHeap = [(0, 0, 0)]
        visited = set()

        ROWS, COLS = len(heights), len(heights[0])

        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        
        while minHeap and (ROWS - 1, COLS - 1) not in visited:
            w, r, c = heapq.heappop(minHeap)

            if (r, c) in visited:
                continue

            if r == ROWS - 1 and c == COLS - 1:
                return w

            visited.add((r, c))
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if min(nr, nc) >= 0 and nr < ROWS and nc < COLS and (nr, nc) not in visited:
                    nw = max(w, abs(heights[nr][nc] - heights[r][c]))
                    heapq.heappush(minHeap, (nw, nr, nc))
        return -1            
