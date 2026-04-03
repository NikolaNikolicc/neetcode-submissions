class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        hashMap = {}
        for i, num in enumerate(nums):
            hashMap[num] = i
        
        def twoSum(pos, target):
            res = []
            start = pos + 1
            end = len(nums) - 1
            while start < (start + end) / 2:
                if target - nums[start] in hashMap and hashMap[target - nums[start]] > start:
                    res.append([nums[start], target - nums[start]])

                start += 1
            return res

        
        output = []
        for i in range(len(nums)):
            # if i - 1 > 0 and nums[i] == nums[i - 1]:
            #     continue
            pairs = twoSum(i, -nums[i])
            for pair in pairs:
                hlp = [nums[i]] + pair
                # print(hlp)
                if hlp not in output:
                    output.append(hlp)
        return list(output)