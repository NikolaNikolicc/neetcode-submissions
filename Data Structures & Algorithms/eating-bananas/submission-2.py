class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # k(number_of_bananas) * h (number_of_hours) > total_number_of_bananas
        # minimize k

        def canEat(k: int, h: int) -> bool:
            res = 0
            for pile in piles:
                res += (pile + k - 1) // k
            return res <= h

        s, e = 1, max(piles)

        result = -1
        while s <= e:
            mid = (s + e) // 2
            res = canEat(mid, h)
            if res:
                result = mid
                e = mid - 1
            else:
                s = mid + 1
        return result
