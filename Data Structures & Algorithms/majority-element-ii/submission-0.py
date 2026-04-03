class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        target = len(nums) // 3
        cnt = defaultdict(int)
        for elem in nums:
            cnt[elem] += 1

        res = [key for key, val in cnt.items() if val > target]
        return res