class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        adj = defaultdict(list)
        for src1, dst1, price in flights:
            adj[src1].append((price, dst1))

        # return final price
        def backtrack(fr: int, credits: int) -> int:

            if credits > k + 1:
                return -1            

            if fr == dst:
                return 0

            minPrice = float("inf")
            for price, to in adj[fr]:
                res = backtrack(to, credits + 1)
                if res != -1:
                    minPrice = min(minPrice, price + res)

            return minPrice
                    

        res = backtrack(src, 0)
        return res if res != float("inf") else -1