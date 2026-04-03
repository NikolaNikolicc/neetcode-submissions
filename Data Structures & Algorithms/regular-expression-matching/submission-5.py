class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        row = [False for _ in range(len(p) + 1)]

        row[-1] = True
        for p1 in range(len(p) - 1, -1, -1):
            if p1 < len(p) - 1 and p[p1 + 1] == "*":
                row[p1] = row[p1 + 2]
        
        for s1 in reversed(range(len(s))):
            new = [False for _ in range(len(p) + 1)]
            for p1 in reversed(range(len(p))):

                match = s[s1] == p[p1] or p[p1] == "."
                
                if p1 < len(p) - 1 and p[p1 + 1] == "*":
                    new[p1] = new[p1 + 2]
                    if match:
                        new[p1] = new[p1] or row[p1]
                elif match:
                    new[p1] = row[p1 + 1]
            
            row = new
        return row[0]
                