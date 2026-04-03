from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        adj = defaultdict(list)

        for time in times:
            adj[time[0]].append((time[2], time[1]))

        paths = {}
        heap = [(0, k)]

        while heap and len(paths) != n:

            w, dst = heapq.heappop(heap)

            if dst in paths:
                continue

            paths[dst] = w

            for pair in adj[dst]:
                if pair[1] not in paths:
                    heapq.heappush(heap, (pair[0] + w, pair[1]))

        return max(paths.values()) if len(paths) == n else -1