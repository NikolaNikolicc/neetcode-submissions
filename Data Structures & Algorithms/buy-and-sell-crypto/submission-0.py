class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        buy = 0
        maxProfit = 0
        for p in range(1, len(prices)):
            if prices[buy] > prices[p]:
                buy = p

            if prices[p] - prices[buy] > maxProfit:
                maxProfit = prices[p] - prices[buy]
        return maxProfit
        