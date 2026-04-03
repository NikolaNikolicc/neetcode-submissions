class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = []
        subset = []
        def dfs(pos):
            if pos >= len(nums):
                subsets.append(subset[:])
                return

            subset.append(nums[pos])
            dfs(pos + 1)
            subset.pop()
            dfs(pos + 1)

        dfs(0)
        return subsets