class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0

        one, two = 0, nums[0]
        for i in range(1, len(nums)):
            tmp = two
            two = max(one + nums[i], two)
            one = tmp
        return two