class Solution:
    def getSum(self, a: int, b: int) -> int:
        num = 1
        carry = 0

        res = 0
        for i in range(32):

            res |= (a & num) ^ (b & num) ^ carry
            
            # carry
            if (a & num and b & num) or (a & num and carry) or (b & num and carry):
                carry = 1
            else:
                carry = 0
            num <<= 1
            if carry:
                carry = num

            # print("res: " + str(res) + " carry: " + str(carry))

        mask = 0xFFFFFFFF
        if res > 0x7FFFFFFF:
            res = ~(res ^ mask)
                        

        return res