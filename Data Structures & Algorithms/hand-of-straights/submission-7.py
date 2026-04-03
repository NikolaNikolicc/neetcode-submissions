class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:

        if len(hand) % groupSize != 0:
            return False

        if groupSize == 1:
            return True
        
        minVal = float("inf")
        counter = defaultdict(int)
        for elem in hand:
            minVal = min(minVal, elem)
            counter[elem] += 1

        visited = set()
        timers = defaultdict(int)
        groups = 0
        
        # visited.add(minVal)
        # timers[groupSize - 1] = 1
        while len(visited) != len(counter.keys()):
            if groups == 0:
                while minVal not in counter:
                    minVal += 1
                visited.add(minVal)
                timers[groupSize - 1] = counter[minVal]
                groups = counter[minVal]
            else:
                if groups < counter[minVal]:
                    timers[groupSize] += counter[minVal] - groups
                    groups = counter[minVal]
                                        
                if groups == counter[minVal]:
                    for i in range(1, groupSize + 1):
                        # if i > 0:
                        if i == 1:
                            groups -= timers[i]
                        
                        timers[i] = timers[i + 1]
                else:
                    return False
                
                visited.add(minVal)

            # print("minVal: " + str(minVal) + " groups: " + str(groups) + " timers: " + str(timers))
            minVal += 1

        return groups == 0