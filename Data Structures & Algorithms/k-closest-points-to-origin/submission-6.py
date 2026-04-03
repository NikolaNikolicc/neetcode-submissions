class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
            minHeap = []

            distance = lambda x: x[0]**2 + x[1]**2 
            for point in points:
                minHeap.append([distance(point), point[0], point[1]])

            heapq.heapify(minHeap)

            res = []
            for i in range(k):
                res.append(heapq.heappop(minHeap)[1:])

            return res
