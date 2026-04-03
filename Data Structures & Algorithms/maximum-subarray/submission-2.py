class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum, currSum = -1001, 0

        for num in nums:
            if currSum < 0:
                currSum = 0
            
            currSum += num
            maxSum = max(currSum, maxSum)

        return maxSum