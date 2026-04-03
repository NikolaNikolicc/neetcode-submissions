class Solution:
    def isHappy(self, n: int) -> bool:
        squares = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
        visited = set()
        def calc(n):
            res = 0

            while n:
                carry = n % 10
                n //= 10

                res += squares[carry]

            return res

        while n != 1 and n not in visited:
            visited.add(n)
            n = calc(n)

        return n == 1