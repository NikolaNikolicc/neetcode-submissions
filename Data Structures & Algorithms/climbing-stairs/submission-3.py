class Solution:
    def climbStairs(self, n: int) -> int:
        

        def dfs(pos):
            if pos == n:
                return 1
            if pos > n:
                return 0
            
            return dfs(pos + 1) + dfs(pos + 2)

        return dfs(0)