class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = defaultdict(int)

        for l in s:
            letters[l] += 1

        for l in t:
            letters[l] -= 1

        return max(letters.values()) == 0 and min(letters.values()) == 0