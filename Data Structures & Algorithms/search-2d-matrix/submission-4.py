class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def searchRow(target: int) -> int:
            up, down = 0, len(matrix) - 1
            while up <= down:
                mid = (up + down) // 2
                if matrix[mid][0] > target:
                    down = mid - 1
                elif matrix[mid][-1] < target:
                    up = mid + 1
                elif matrix[mid][0] <= target and matrix[mid][-1] >= target:
                    return mid
            return -1

        row = searchRow(target)
        if row == -1: 
            return False
        
        nums = matrix[row]
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return False
                    