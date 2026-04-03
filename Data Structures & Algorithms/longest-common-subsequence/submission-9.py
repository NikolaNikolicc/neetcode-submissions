class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # swap strings if needed so we have longner text in text2
        if len(text1) > len(text2):
            text1, text2 = text2, text1
            
        oldRow = [0]*(len(text1) + 1)
        
        for r in range(len(text2) - 1, -1, -1):
            prev = 0
            for c in range(len(text1) - 1, -1, -1):
                tmp = oldRow[c]
                if text2[r] == text1[c]:
                    oldRow[c] = 1 + prev
                else:
                    oldRow[c] = max(oldRow[c], oldRow[c + 1])

                prev = tmp
            

        return oldRow[0]