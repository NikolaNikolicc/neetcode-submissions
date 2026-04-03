class Solution:
    def rob(self, nums: List[int]) -> int:

        one, two = 0, 0
        for num in nums:
            tmp = max(num + one, two)
            one = two
            two = tmp

        return two


# [2,9,8,3,6]