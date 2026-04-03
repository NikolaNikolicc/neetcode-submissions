class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        
        helper = [False for _ in range(len(p) + 1)]
        helper[-1] = True

        for s1 in range(len(s), -1, -1):
            row = [False for _ in range(len(p) + 1)]
            row[-1] = (s1 == len(s))
            for p1 in range(len(p) - 1, -1, -1):
                match = s1 < len(s) and (s[s1] == p[p1] or p[p1] == ".")
                
                if p1 < len(p) - 1 and p[p1 + 1] == "*":
                    row[p1] = row[p1 + 2]
                    if match:
                        row[p1] = row[p1] or helper[p1]
                elif match:
                    row[p1] = helper[p1 + 1]

            helper = row
        return helper[0]
                