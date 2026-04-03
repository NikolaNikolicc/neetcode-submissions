class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        elements = {}

        for idx, val in enumerate(nums):
            if target - val in elements:
                return [elements[target - val], idx]
            elements[val] = idx 
        return None