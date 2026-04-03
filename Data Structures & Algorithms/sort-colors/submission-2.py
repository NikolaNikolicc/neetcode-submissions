class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = Counter(nums)
        ctr = 0
        for key in sorted(bucket.keys()):
            while bucket[key]:
                nums[ctr] = key
                ctr += 1
                bucket[key] -= 1