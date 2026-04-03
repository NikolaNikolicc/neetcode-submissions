# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        if not pairs:
            return []
        insertionSortResultList = [pairs[:]]

        for i in range(1, len(pairs)):
            j = i - 1
            item = pairs[i]
            while j >= 0 and pairs[j].key > item.key:
                pairs[j + 1] = pairs[j]
                j -= 1
            pairs[j + 1] = item
            insertionSortResultList.append(pairs[:])
            # tmp = pairs[j]
            # pairs[j] = pairs[i]
            # pairs[i] = pairs[j]
        return insertionSortResultList
            