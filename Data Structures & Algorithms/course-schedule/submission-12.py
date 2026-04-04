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
            
            if adjList[rootIdx] == []:
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
