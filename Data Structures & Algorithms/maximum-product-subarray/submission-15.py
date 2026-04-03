class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maximum, minimum = nums[0], nums[0]
        globalMax = nums[0]

        for i in range(1, len(nums)):
            tmax = nums[i] * maximum
            tmin = nums[i] * minimum
            maximum = max(nums[i], tmax, tmin)
            minimum = min(nums[i], tmax, tmin)
            globalMax = max(globalMax, maximum)

        return globalMax