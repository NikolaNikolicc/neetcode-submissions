class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1

        one, two = 0, 0
        if n - 1 >= 0:
            one = self.climbStairs(n - 1)

        if n - 2 >= 0:
            two = self.climbStairs(n - 2)
        
        return one + two