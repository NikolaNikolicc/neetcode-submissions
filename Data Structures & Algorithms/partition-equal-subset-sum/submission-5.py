class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)

        target = total // 2
        if total % 2:
            return False

        sums = set([0])
        for i in range(len(nums) - 1, -1, -1):
            print(sums)
            newSums = set()
            for s in sums:
                if s == target:
                    return True
                
                newSums.add(nums[i])
                newSums.add(nums[i] + s)
            sums |= newSums
        print(sums)
        return target in sums        