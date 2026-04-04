class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        swindow = set()

        for i in range(len(nums)):
            if i > k:
                swindow.remove(nums[i - k - 1])

            if nums[i] in swindow:
                return True
            swindow.add(nums[i])
        return False