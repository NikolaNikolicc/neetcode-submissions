class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjecency = {i:[] for i in range(1, n + 1)}

        for src, dst, t in times:
            adjecency[src].append((dst, t))

        minHeap = [(0, k)]

        shortest = {i: -1 for i in range(1, n + 1)}

        while minHeap:
            w1, node = heapq.heappop(minHeap)

            if shortest[node] != -1:
                continue

            shortest[node] = w1

            for dst, w2 in adjecency[node]:
                if shortest[dst] == -1:
                    heapq.heappush(minHeap, (w1 + w2, dst))


        ret = float("-inf")
        for time in shortest.values():
            if time == -1:
                return -1
            ret = max(ret, time)
        return ret