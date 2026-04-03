class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        c = 0
        pairs = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        while c < len(s):
            ch = s[c]
            old = c
            if c < len(s) - 1:
                if ch == "I" and s[c + 1] == "V":
                    res += 4
                    c += 1
                elif ch == "I" and s[c + 1] == "X":
                    res += 9
                    c += 1
                elif ch == "X" and s[c + 1] == "L":
                    res += 40
                    c += 1
                elif ch == "X" and s[c + 1] == "C":
                    res += 90
                    c += 1
                elif ch == "C" and s[c + 1] == "D":
                    res += 400
                    c += 1
                elif ch == "C" and s[c + 1] == "M":
                    res += 900
                    c += 1
            if old == c:
                res += pairs[ch]
            c += 1
        return res