class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")]*(amount + 1)
        dp[0] = 0

        for coin in coins:
            for a in range(1, amount + 1):
                if a == coin:
                    dp[a] = 1

                if a - coin >= 0 and dp[a - coin] != float("inf"):
                    dp[a] = min(dp[a], 1 + dp[a - coin])
                
        return dp[-1] if dp[-1] != float("inf") else -1