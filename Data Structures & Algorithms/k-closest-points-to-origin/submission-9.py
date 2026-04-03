class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def calc(point: List[int]) -> int:
            x, y = point[0], point[1]
            return math.sqrt(x*x + y*y)
        
        distance = [(-calc(point), point) for point in points]
        heapq.heapify(distance)

        while  len(distance) > k:
            heapq.heappop(distance)

        return [dist[1] for dist in distance]