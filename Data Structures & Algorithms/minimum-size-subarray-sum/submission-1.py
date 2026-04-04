class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0

        suma = 0
        minLen = float("inf")

        for r in range(len(nums)):
            suma += nums[r]
            while suma >= target and l <= r:
                minLen = min(minLen, r - l + 1)
                suma -= nums[l]
                l += 1
        return minLen if minLen != float("inf") else 0