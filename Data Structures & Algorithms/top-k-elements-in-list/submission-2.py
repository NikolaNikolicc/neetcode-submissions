class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = defaultdict(int)


        for num in nums:
            d[num] += 1

        maxHeap = []
        for key, val in d.items():
            heapq.heappush(maxHeap, (-val, key))

        ret = []
        for _ in range(k):
            r = heapq.heappop(maxHeap)
            ret.append(r[1])

        return ret

        