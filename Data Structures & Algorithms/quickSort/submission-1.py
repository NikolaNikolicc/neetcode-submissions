# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        
        if not pairs:
            return []
        
        def quick(s, e):

            if s >= e:
                return

            left = s
            pivot = pairs[e]

            for i in range(s, e):
                if pairs[i].key < pivot.key:
                    tmp = pairs[i]
                    pairs[i] = pairs[left]
                    pairs[left] = tmp
                    # pairs[left], pairs[i] = pairs[i], pairs[left]
                    left += 1

            # pairs[left], pivot = pivot, pairs[left]
            pairs[e] = pairs[left]
            pairs[left] = pivot
            quick(s, left - 1)
            quick(left + 1, e)

        quick(0, len(pairs) - 1)
        return pairs