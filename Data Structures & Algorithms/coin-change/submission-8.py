class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        values = [float("inf") for i in range(amount + 1)]
        values[0] = 0
        
        for v in range(amount + 1):
            for coin in coins:
                if coin == amount:
                    values[v] = 1
                if v - coin >= 0 and values[v - coin] != float("inf"):
                    values[v] = min(1 + values[v - coin], values[v])
        return values[-1] if values[-1] != float("inf") else -1