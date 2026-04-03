class Solution:
    def numDecodings(self, s: str) -> int:
        one, two = 1, 1
        for i in range(len(s)):
            tmp = 0
            if s[i] != "0":
                tmp += one
            
            if i > 0 and s[i - 1] != "0" and int(s[i-1:i+1]) <= 26:
                tmp += two
            
            two = one
            one = tmp
        return one