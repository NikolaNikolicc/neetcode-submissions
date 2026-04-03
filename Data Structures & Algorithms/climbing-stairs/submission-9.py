class Solution:
    def climbStairs(self, n: int) -> int:
        if not n:
            return 0
        one, two = 1, 1
        for i in range(1, n):
            tmp = two
            two = one + two
            one = tmp
        return two
