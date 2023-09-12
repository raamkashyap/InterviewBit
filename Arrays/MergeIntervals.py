# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param new_interval, a Interval
    # @return a list of Interval
    def insert(self, intervals, new_interval):
        if len(intervals) == 0:
            return [newInterval]
        result = []
        result.append(newInterval)
        for i in range(0,len(intervals)):
            a = result.pop()
            b = intervals[i]
            if a.start > b.end:
                result.append(b)
                result.append(a)
            elif a.end < b.start:
                result.append(a)
                result.append(b)
            else:
                start = min(a.start, b.start)
                end = max(a.end, b.end)
                result.append(Interval(start, end))
        
        return result