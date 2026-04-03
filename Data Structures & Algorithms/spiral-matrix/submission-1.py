class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top, down = 0, len(matrix) 
        left, right = 0, len(matrix[0])

        res = []
        while top < down and left < right:
            for i in range(left, right):
                res.append(matrix[top][i])
            top +=1 
            for i in range(top, down):
                res.append(matrix[i][right - 1])
            right -= 1

            if top >= down or left >= right:
                break

            for i in range(right - 1, left - 1, -1):
                res.append(matrix[down - 1][i])
            down -= 1
            for i in range(down - 1, top - 1, -1):
                res.append(matrix[i][left])
            left += 1

        return res