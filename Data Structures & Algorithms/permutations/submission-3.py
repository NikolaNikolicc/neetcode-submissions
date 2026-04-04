class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        pool = [True for _ in range(len(nums))]

        permutations = []
        permutation = []
        def dfs(pos):
            if pos == len(nums):
                permutations.append(permutation[:])
                return

            for i in range(len(nums)):
                if pool[i]:
                    pool[i] = False
                    permutation.append(nums[i])
                    dfs(pos + 1)
                    permutation.pop()
                    pool[i] = True
            
        dfs(0)
        return permutations
