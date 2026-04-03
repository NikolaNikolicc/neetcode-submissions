from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)

        longest = 0
        l = 0

        maxf = 0
        for r in range(len(s)):
            count[s[r]] += 1
            maxf = max(maxf, count[s[r]])
            
            while r - l + 1 - maxf > k:
                count[s[l]] -= 1
                l += 1

            longest = max(longest, r - l + 1)
            

        return longest