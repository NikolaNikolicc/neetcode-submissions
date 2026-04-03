"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        days = []
        intervals.sort(key = lambda i: i.start)
        for i in range(len(intervals)):
            if days and days[0] <= intervals[i].start:
                heapq.heappop(days)
            heapq.heappush(days, intervals[i].end)

        return len(days)
