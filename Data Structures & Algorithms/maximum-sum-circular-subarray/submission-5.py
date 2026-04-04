class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:

        currMax, currMin, maxSum, minSum = 0, 0, nums[0], nums[0]
        for num in nums:
            currMax += num
            currMin += num

            maxSum = max(maxSum, currMax)
            if currMax < 0:
                currMax = 0

            minSum = min(minSum, currMin)
            if currMin > 0:
                currMin = 0

        return max(maxSum, sum(nums) - minSum) if maxSum >= 0 else maxSum