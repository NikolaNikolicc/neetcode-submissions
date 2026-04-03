class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        result = []
        sub = []
        def dfs(i):
            if i == len(nums):
                result.append(sub[:])
                return
            
            sub.append(nums[i])
            dfs(i + 1)
            sub.pop()

            dfs(i + 1)

        dfs(0)
        return result