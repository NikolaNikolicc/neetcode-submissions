class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
 
        combinations = []
        combination = []
        def comb(pos):
            if len(combination) == k:
                combinations.append(combination[:])
                return

            for i in range(pos, n + 1):
                combination.append(i)
                comb(i + 1)
                combination.pop()

        comb(1)
        return combinations