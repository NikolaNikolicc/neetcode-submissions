class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        while l + 1 < len(height) and height[l + 1] >= height[l]:
            l += 1

        r = len(height) - 1
        while r - 1 >= 0 and height[r - 1] >= height[r]:
            r -= 1

        heighest = [0] * len(height)

        currMax = height[r]
        for i in range(r - 1, l, -1):
            currMax = max(currMax, height[i])
            heighest[i] = currMax

        print(heighest)
        accumulator = 0
        for i in range(l + 1, r):
            if height[i] >= height[l]:
                l = i
                continue
            accumulator += min(height[l], heighest[i]) - height[i]

        return accumulator