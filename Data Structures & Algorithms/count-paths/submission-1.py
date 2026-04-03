class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        helper = [0]*n
        helper[n - 1] = 1
        for i in range(m - 1, -1, -1):
            row = [0]*n
            for j in range(n - 1, -1, -1):
                row[j] = helper[j]
                if j < n - 1:
                    row[j] += row[j + 1]

            helper = row
            print(helper)

        return helper[0]