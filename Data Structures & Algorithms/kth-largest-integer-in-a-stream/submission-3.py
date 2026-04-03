class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.h = nums
        self.k = k
        heapq.heapify(self.h)
        while len(nums) > k:
            elem = heapq.heappop(self.h)

    def add(self, val: int) -> int:
        heapq.heappush(self.h, val)
        if len(self.h) > self.k:
            heapq.heappop(self.h)
        return self.h[0]
