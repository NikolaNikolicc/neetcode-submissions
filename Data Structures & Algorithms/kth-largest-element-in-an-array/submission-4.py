class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        def quickSort(left, right):
            pivot = right
            l = left
            
            for i in range(left, right):
                if nums[pivot] > nums[i]:
                    nums[l], nums[i] = nums[i], nums[l]
                    l += 1
                i += 1

            nums[pivot], nums[l] = nums[l], nums[pivot]
            
            if l == k:
                return nums[l]
            elif l < k:
                return quickSort(l + 1, right)
            else:
                return quickSort(left, l - 1)

        k = len(nums) - k
        return quickSort(0, len(nums) - 1)