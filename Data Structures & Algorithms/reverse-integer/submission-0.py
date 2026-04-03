class Solution:
    def reverse(self, x: int) -> int:
        
        neg = (x < 0)
        if x < 0:
            x *= -1

        mask = 0xFFFFFFFF

        strx = list(str(x))

        l, r = 0, len(strx) - 1
        while l < r:
            strx[l], strx[r] = strx[r], strx[l]
            l += 1
            r -= 1

        x = int("".join(strx))

        if x > mask:
            return 0        
        
        return -x if neg else x