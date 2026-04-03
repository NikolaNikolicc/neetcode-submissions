class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = set()
        maxLen = 0
        l = 0
        for r in range(len(s)):
            while l < r and s[r] in longest:
                longest.remove(s[l])
                l += 1

            longest.add(s[r])
            maxLen = max(maxLen, r - l + 1)
        
        return maxLen