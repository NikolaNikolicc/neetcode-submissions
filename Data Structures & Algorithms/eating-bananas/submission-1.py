class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # k from min(1) to max(piles)

        def canEat(val: int) -> bool:
            res = 0
            for pile in piles:
                res += (pile + val - 1) // val
            return res <= h

        l, r = 1, max(piles)
        mid = 1
        while l < r:
            mid = (l + r) // 2
            res = canEat(mid)
            if res: 
                # can eat -> True
                r = mid
            else: 
                # can't eat -> False
                l = mid + 1
        mid = (r + l) // 2
        return mid