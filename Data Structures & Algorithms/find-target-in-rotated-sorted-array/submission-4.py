class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            
            if nums[l] <= nums[mid] and (nums[l] > target or target > nums[mid]):
                print("case 1")
                l = mid + 1
            elif nums[r] >= nums[mid] and (nums[r] < target or target < nums[mid]):
                print("case 2")
                r = mid - 1
            else:

                    if nums[mid] == target:
                        return mid
                    elif nums[mid] > target:
                        r = mid - 1
                    else:
                        l = mid + 1
        return -1