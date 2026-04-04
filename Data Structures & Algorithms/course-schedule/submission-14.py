from collections import defaultdict
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = defaultdict(list)

        for prereq in prerequisites:
            adjList[prereq[0]].append(prereq[1])

        result =[]
        visited = set()
        def dfs(rootIdx):
            if rootIdx in visited:
                return False
            
            if rootIdx in adjList and adjList[rootIdx] == []:
                return True

            result.append(rootIdx)
            visited.add(rootIdx)
            for nei in adjList[rootIdx]:
                if not dfs(nei):
                    return False
            visited.remove(rootIdx)
            adjList[rootIdx] = []
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        print(result)
        return True


sol = Solution()
print(sol.canFinish(2, [[1,0]])) # True
print(sol.canFinish(2, [[1,0],[0,1]])) # False
print(sol.canFinish(3, [[0,1],[0,2],[1,2]])) # True
print(sol.canFinish(
    8,
    [
        [1, 0],  # 1 depends on 0
        [2, 0],  # 2 depends on 0
        [3, 1],  # 3 depends on 1
        [3, 2],  # 3 depends on 2
        [4, 1],  # 4 depends on 1
        [5, 3],  # 5 depends on 3
        [6, 4],  # 6 depends on 4
        [6, 5],  # 6 depends on 5
        [7, 6],  # 7 depends on 6
    ]
))  # True