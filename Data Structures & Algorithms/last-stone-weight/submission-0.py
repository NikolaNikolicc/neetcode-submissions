class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxheap = [-weight for weight in stones]
        heapq.heapify(maxheap)
        while(len(maxheap) > 1):
            val1 = heapq.heappop(maxheap)
            val2 = heapq.heappop(maxheap)

            smash = val1 - val2

            if smash:
                heapq.heappush(maxheap, smash)

        return -maxheap[0] if len(maxheap) > 0 else 0