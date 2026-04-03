class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        map = {value: idx for idx, value in enumerate(nums)}
        res = 0
        for num in nums:
            if num - 1 not in map.keys():
                cnt = 0
                tmp = num
                while tmp in map.keys():
                    cnt += 1
                    tmp += 1
                res = max(res, cnt)

        return res