class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        cash = defaultdict(int)

        def haveChange(amount):
            if amount == 5:
                return True
            elif amount == 10 and cash[5] >= 1:
                cash[5] -= 1
                return True
            elif amount == 20:
                if cash[10] >= 1 and cash[5] >= 1:
                    cash[10] -= 1
                    cash[5] -= 1
                    return True
                elif cash[5] >= 3:
                    cash[5] -= 3
                    return True
            return False

        while bills:
            val = bills.pop(0)
            if not haveChange(val):
                return False
            else:
                cash[val] += 1
        return True