class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def calcDistance(point):
            return (point[0])**2 + (point[1])**2

        def quickSort(s, e):
            pivot = points[e]
            pivotDist = calcDistance(pivot)
            left = s
            for i in range(s, e):
                if calcDistance(points[i]) < pivotDist:
                    points[left], points[i] = points[i], points[left]
                    left += 1

            points[left], points[e] = points[e], points[left]

            if k <= left and left - 1 >= s:
                quickSort(s, left - 1)
            if k > left and left + 1 <= e:
                quickSort(left + 1, e)

        quickSort(0, len(points) - 1)
        return points[:k]