class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cache = {}
        def dfs(sell, buy):

            if sell >= len(prices):
                return 0

            while sell < len(prices) - 1 and prices[sell] > prices[sell + 1]:
                if buy == sell:
                    buy += 1
                sell += 1

            if (sell, buy) in cache:
                return cache[(sell, buy)]

            if buy == len(prices) - 1:
                cache[(sell, buy)] = prices[buy] - prices[sell]
                return cache[(sell, buy)]

            one = dfs(sell, buy + 1)
            two = prices[buy] - prices[sell] + dfs(buy + 2, buy + 2)

            cache[(sell, buy)] = max(one, two)

            return cache[(sell, buy)]

            
        return dfs(0, 0)
