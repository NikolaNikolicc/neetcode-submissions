from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        s, e = 0, len(nums) - 1
        pivot = len(nums)
        while True:
            pivot = e
            j = s
            # print(f"s: {s}, e: {e}, j: {j}")
            for i in range(s, pivot):
                if nums[i] >= nums[pivot]:
                    nums[j], nums[i] = nums[i], nums[j]
                    j += 1
            nums[j], nums[pivot] = nums[pivot], nums[j]
            if j < k - 1:
                s = j + 1
            elif j > k - 1:
                e = j - 1
            else:
                return nums[j]
            # print(f"nums: {nums}, pivot: {pivot}")
    