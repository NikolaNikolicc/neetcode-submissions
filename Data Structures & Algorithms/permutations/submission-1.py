class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        permutation = []

        def dfs(arr):

            if len(permutation) == len(nums):
                permutations.append(permutation[:])
                return

            for i in range(len(arr)):
                permutation.append(arr[i])
                dfs(arr[:i] + arr[i + 1:])
                permutation.pop()

        dfs(nums)
        return permutations