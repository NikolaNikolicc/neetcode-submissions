class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        helper = [0]*(n + 1)
        helper[n - 1] = 1
        for i in range(m - 1, -1, -1):
            row = [0]*(n + 1)
            for j in range(n - 1, -1, -1):
                row[j] = helper[j] + row[j + 1]
            helper = row

        return helper[0]