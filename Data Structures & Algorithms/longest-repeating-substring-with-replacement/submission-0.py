from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)

        longest = 0
        l = 0
        for r in range(len(s)):
            count[s[r]] += 1

            while r - l + 1 - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1

            if r - l + 1 - max(count.values()) <= k:
                longest = max(longest, r - l + 1)
            

        return longest