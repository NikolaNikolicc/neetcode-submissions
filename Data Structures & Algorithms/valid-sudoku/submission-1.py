class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        self.SIZE = 3
        squares = [[set() for _ in range(self.SIZE)] for _ in range(self.SIZE)]
        rows = [set() for _ in range(self.SIZE**2)]
        cols = [set() for _ in range(self.SIZE**2)]

        for r in range(self.SIZE**2):
            for c in range(self.SIZE**2):
                elem = board[r][c]
                if elem == ".":
                    continue
                rr = r // 3
                cc = c // 3
                if elem in rows[r] or elem in cols[c] or elem in squares[rr][cc]:
                    return False

                rows[r].add(elem)
                cols[c].add(elem)
                squares[rr][cc].add(elem)

        return True