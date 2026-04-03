class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        res = nums[0]
        while l <= r:
            if nums[l] <= nums[r]:
                res = min(res, nums[l])
                return res

            mid = (l + r) // 2

            if nums[mid] >= nums[l]:
                l += 1
            else:
                r -= 1