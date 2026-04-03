class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # swap strings if needed so we have longner text in text2
        if len(text1) > len(text2):
            text1, text2 = text2, text1
            
        oldRow = [0]*(len(text1) + 1)
        newRow = [0]*(len(text1) + 1)
        for r in range(len(text2) - 1, -1, -1):
            for c in range(len(text1) - 1, -1, -1):
                if text2[r] == text1[c]:
                    newRow[c] = 1 + oldRow[c + 1]
                else:
                    newRow[c] = max(oldRow[c], newRow[c + 1])

            oldRow = newRow[:]

        return newRow[0]