class Solution:
    # [-5, -1]
    # cs = -4
    # ms = -4
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        currSum = nums[0]
        for i in range(1, len(nums)):
            n = nums[i]

            if currSum + n < currSum and currSum + n < 0:
                currSum = n
            else:
                currSum = max(currSum + n, n)
            maxSum = max(currSum, maxSum)

        return maxSum