class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        leftover = [len(s) - i for i in range(len(s) + 1)]

        for i in range(len(s) - 1, -1, -1):
            leftover[i] = leftover[i + 1] + 1
            for w in dictionary:
                if i + len(w) <= len(s) and w == s[i:i + len(w)]:
                    leftover[i] = min(leftover[i], leftover[i + len(w)])

        return leftover[0]