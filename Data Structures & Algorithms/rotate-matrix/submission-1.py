class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:

        ROWS, COLS = len(matrix), len(matrix[0])
        left, right = 0, COLS - 1
        for r in range(ROWS // 2):
            for c in range(left, right):
                tmp = matrix[r][c]

                matrix[r][c] = matrix[ROWS - c - 1][left]

                matrix[ROWS - c - 1][left] = matrix[ROWS - r - 1][COLS - c - 1]

                matrix[ROWS - r - 1][COLS - c - 1] = matrix[c][right]

                matrix[c][right] = tmp

            right -= 1
            left += 1