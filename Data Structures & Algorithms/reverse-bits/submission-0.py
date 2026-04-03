class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            bit = n & 1
            n >>= 1
            res |= (bit << (32 - i - 1))

        return res