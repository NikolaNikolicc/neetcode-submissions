class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0: return 0
        values = [float("inf") for i in range(amount + 1)]
        for coin in coins:
            if coin <= amount:
                values[coin] = 1

        for v in range(amount + 1):
            for coin in coins:
                if v - coin > 0 and values[v - coin] != float("inf"):
                    values[v] = min(1 + values[v - coin], values[v])
        return values[-1] if values[-1] != float("inf") else -1