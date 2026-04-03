class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxArea = 0
        for h in range(len(heights)):
            start = h
            while stack and stack[-1][0] > heights[h]:
                height, index = stack.pop()
                maxArea = max(maxArea, height * (h - index))
                start = index

            stack.append((heights[h], start))

        while stack:
            height, index = stack.pop()
            maxArea = max(maxArea, height * (len(heights) - index))

        return maxArea