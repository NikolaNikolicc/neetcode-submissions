class Solution:
    def numDecodings(self, s: str) -> int:
        # constraints

        # number cannot start with zero

        # number cannot be bigger than 26 
        self.valid = 0
        def dfs(pos):

            # base case
            if pos == len(s):
                self.valid += 1
                return
            
            # base case
            if s[pos] == "0":
                return
            # try with one digit
            dfs(pos + 1)
            # try with two digits
            if pos + 1 < len(s) and (int(s[pos:pos + 2])) < 27:
                dfs(pos + 2)

        dfs(0)
        return self.valid