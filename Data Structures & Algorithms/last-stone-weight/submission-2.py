class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            s1 = heapq.heappop(stones)
            s2 = heapq.heappop(stones)
            diff = abs(s1 - s2)
            if diff:
                heapq.heappush(stones, -diff)
        return 0 if not len(stones) else -stones[0]