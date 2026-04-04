class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix = [0] * len(nums)
        sum = 0
        for i, num in enumerate(nums):
            sum += num
            self.prefix[i] = sum

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right] - self.prefix[left - 1] if left else self.prefix[right]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)