class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [0] * len(prices)
        dp[-1] = 0
        prices.append(float("-inf"))
        for i in range(len(prices) - 2, -1, -1):
            dp[i] = max(dp[i], prices[i + 1] - prices[i])
            if i < len(prices) - 2:
                dp[i] += dp[i + 1]

        return dp[0]