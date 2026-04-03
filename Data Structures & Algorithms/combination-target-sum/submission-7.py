class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        sums = []
        curr = []
        def dfs(pos, totalSum):
            if pos >= len(nums) or totalSum > target:
                return
                
            if totalSum == target:
                sums.append(curr[:])
                return

            curr.append(nums[pos])
            dfs(pos, totalSum + nums[pos])
            curr.pop()

            dfs(pos + 1, totalSum)

        dfs(0, 0)
        return sums