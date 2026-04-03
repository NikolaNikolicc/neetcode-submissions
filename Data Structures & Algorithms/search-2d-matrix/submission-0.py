class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        def findInRow(r):
            s, e = 0, len(matrix[r]) - 1
            row = matrix[r]
            while s <= e:
                
                m = (s + e) // 2

                if row[m] < target:
                    s = m + 1
                elif row[m] > target:
                    e = m - 1
                else:
                    return True

            return False

        if not matrix or len(matrix) == 0:
            return False
        
        rs, re = 0, len(matrix) - 1
        width = len(matrix[0])
        while rs <= re:
            
            rm = (rs + re) // 2

            if matrix[rm][0] > target:
                re = rm - 1
            elif matrix[rm][width - 1] < target:
                rs = rm + 1
            else:
                return findInRow(rm)
        
        return False
