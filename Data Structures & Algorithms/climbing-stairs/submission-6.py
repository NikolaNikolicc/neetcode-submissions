class Solution:
    def climbStairs(self, n: int) -> int:
        
        # one, two = 0, 1

        # for i in range(n):
        #     tmp = two
        #     two = two + one
        #     one = tmp
        # return two
        
        if n <= 0:
            return 1
        if n == 1:
            return 1
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)

# 1 2 3 4 5 
# 5 3 2 1 1
#       o t

