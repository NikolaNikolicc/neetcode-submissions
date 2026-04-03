class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        helper = [0] * (capacity + 1)

        for p in range(len(profit)):
            new = [0] * (capacity + 1)
            for c in range(1, capacity + 1):
                if c - weight[p] >= 0:
                    new[c] = max(helper[c - weight[p]] + profit[p], helper[c])
                else:
                    new[c] = helper[c]
            helper = new

            print(helper)

        return helper[-1]