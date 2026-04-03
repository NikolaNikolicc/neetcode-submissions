class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        combinations = []
        combination = []

        def dfs(pos):

            if sum(combination) == target:
                combinations.append(combination[:])
                return

            if pos >= len(nums) or sum(combination) > target:
                return

            for i in range(pos, len(nums)):
                # every element could be included multiple times
                combination.append(nums[i])
                dfs(i)
                combination.pop()

        dfs(0)
        return combinations