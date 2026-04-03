class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0

        for elem in nums:
            res ^= elem

        return res