class Solution:
    # bfs
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        queue = deque()
        queue.append((sr, sc))
        origigi = image[sr][sc]
        image[sr][sc] = color

        dirs = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        visited = set()
        visited.add((sr, sc))
        ROWS, COLS = len(image), len(image[0])
        while queue:
            qlen = len(queue)

            for i in range(qlen):
                pixelr, pixelc = queue.popleft()

                for dr, dc in dirs:
                    nr, nc = pixelr + dr, pixelc + dc
                    if min(nr, nc) >= 0 and nr < ROWS and nc < COLS and image[nr][nc] == origigi and (nr, nc) not in visited:
                        image[nr][nc] = color
                        queue.append((nr, nc))
                        visited.add((nr, nc))
        return image