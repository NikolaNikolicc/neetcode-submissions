class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key = lambda x: x[1])
        # print(f"Sorted trips: {trips}")
        currCap = 0
        destDrops = defaultdict(int)
        for passengers, fr, to in trips:
            for key in sorted(destDrops.keys()):
                if key <= fr:
                    currCap -= destDrops[key]
                    # print(f"Dropping off {destDrops[key]} passengers at {key}, current capacity: {currCap}")
                    del destDrops[key]
                else:
                    break
                
            if currCap + passengers > capacity:
                return False

            currCap += passengers
            destDrops[to] += passengers

            # print(f"From {fr} to {to}, picked {passengers}, current capacity: {currCap}, drops: {destDrops}")

        return True