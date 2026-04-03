class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        outputList = [[]]

        def dfs(lst, unvisited):
            for i in range(len(unvisited)):
                if len(unvisited) > 0:
                    elem = unvisited.pop(0)
                    lst.append(elem)
                    outputList.append(lst.copy())
                    dfs(lst, unvisited.copy())
                    lst.pop()
                    # unvisited.append(elem)


        dfs([], nums)
        return outputList