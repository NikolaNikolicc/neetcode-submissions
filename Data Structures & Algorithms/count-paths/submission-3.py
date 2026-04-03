class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [0]*(n + 1)
        row[n - 1] = 1
        for i in range(m - 1, -1, -1): 
            for j in range(n - 1, -1, -1):
                row[j] = row[j] + row[j + 1]

        return row[0]