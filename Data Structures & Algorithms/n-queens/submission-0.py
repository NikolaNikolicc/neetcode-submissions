class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isSafe(r, c):                
            for i in range(r):
                if board[i][c] == "Q":
                    return False
            
            i, j = r, c
            while i >= 0 and j >= 0:
                if board[i][j] == "Q":
                    return False
                i -= 1
                j -= 1

            i, j = r, c
            while i >= 0 and j < n:
                if board[i][j] == "Q":
                    return False
                i -= 1
                j += 1

            return True
        

        board = [["." for i in range(n)] for i in range(n)]
        output = []

        def backtrack(r):
            if r == n:
                output.append(["".join(elem) for elem in board])
                return

            for c in range(n):
                if isSafe(r, c):
                    board[r][c] = "Q"
                    backtrack(r + 1)
                    board[r][c] = "."

        backtrack(0)
        return output