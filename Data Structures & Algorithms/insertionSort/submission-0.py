# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        retlist = []
        for j in range(len(pairs)):
            i = j
            while i > 0 and pairs[i].key < pairs[i - 1].key:
                # swap
                tmpkey = pairs[i].key
                tmpval = pairs[i].value

                pairs[i].key = pairs[i - 1].key
                pairs[i].value = pairs[i - 1].value

                pairs[i - 1].key = tmpkey
                pairs[i - 1].value = tmpval

                i -= 1

            currlist = []
            for i in range(len(pairs)):
                currlist.append(Pair(pairs[i].key, pairs[i].value))

            retlist.append(currlist)

        return retlist