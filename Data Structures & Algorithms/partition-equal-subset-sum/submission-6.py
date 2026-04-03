class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        target = total // 2

        if total - 2 * target != 0:
            return False
        
        sums = 1

        for num in nums:
            sums |= sums << num

        return (sums >> target) & 1 == 1      