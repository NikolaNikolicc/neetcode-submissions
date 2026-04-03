class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {}
        def dfs(i, currSum):
            if (i, currSum) in dp:
                return dp[(i, currSum)]
            
            if i == len(coins) or currSum > amount:
                return float("inf")

            if currSum == amount:
                return 0

            dp[(i, currSum)] = min(1 + dfs(i, currSum + coins[i]), dfs(i + 1, currSum))
            return dp[(i, currSum)]

        ret = dfs(0, 0)
        return ret if ret != float("inf") else -1