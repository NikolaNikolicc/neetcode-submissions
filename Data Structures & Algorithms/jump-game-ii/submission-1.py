class Solution:
    def jump(self, nums: List[int]) -> int:

        if len(nums) < 2:
            return 0
        
        l = 0
        cnt = 0

        locmax = nums[l]
        while l != len(nums):
            target = locmax + l
            cnt += 1
            while l != len(nums) and l <= target:
                locmax = max(nums[l], locmax)
                locmax -= 1
                l += 1
                
        return cnt