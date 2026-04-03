class Solution:
    def reorganizeString(self, s: str) -> str:
        ctr = Counter(s)
        maxHeap = []

        for k, v in ctr.items():
            heapq.heappush(maxHeap, (-v, k))

        res = ""
        while maxHeap:
            tmp = None
            if res != "" and maxHeap[0][1] == res[-1]:
                tmp  = heapq.heappop(maxHeap)
            
            if not maxHeap:
                return ""

            value, key = heapq.heappop(maxHeap)

            res += key
            value += 1

            if (value != 0): 
                heapq.heappush(maxHeap, (value, key))
            if tmp:
                heapq.heappush(maxHeap, tmp)    
        return res