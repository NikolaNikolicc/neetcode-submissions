class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cache = {i: 0 for i in range(ord("Z") - ord("A") + 1)}
        
        for task in tasks:
            cache[ord(task) - ord("A")] += 1

        maxHeap = []

        for key, elem in cache.items():
            if elem > 0:
                maxHeap.append((-elem, key))

        heapq.heapify(maxHeap)
        interval = 0
        print(maxHeap)

        queue = collections.deque()

        while queue or maxHeap:
            if not maxHeap and queue and interval - queue[0][0] <= n:
                interval += 1
                continue
            
            if queue and interval - queue[0][0] > n and \
                (not maxHeap or (maxHeap and cache[queue[0][1]] >= cache[maxHeap[0][1]])):
                lastUsed, key = queue.popleft()
            else:
                tmp = heapq.heappop(maxHeap)
                elem = -tmp[0]
                key = tmp[1]
            cache[key] -= 1
            if cache[key] > 0:
                queue.append((interval, key)) 

            interval += 1

        return interval