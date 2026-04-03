class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxStone = max(stones)
        bucket = [0] * (maxStone + 1)

        cnt = len(stones)
        for s in stones:
            bucket[s] += 1

        while cnt > 1:            
            s1 = maxStone
            bucket[maxStone] -= 1
            cnt -= 1

            # we are sure that we will find a stone so we don't need condition maxStone >= 0
            while not bucket[maxStone]: 
                maxStone -= 1

            s2 = maxStone
            bucket[maxStone] -= 1
            cnt -= 1

            diff = abs(s1 - s2)
            if diff:
                cnt += 1
                bucket[diff] += 1
        
            maxStone = max(maxStone, diff)
            while not bucket[maxStone] and maxStone >= 0:
                maxStone -= 1
        return 0 if not cnt else maxStone
