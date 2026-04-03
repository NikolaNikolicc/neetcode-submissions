class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)

        visited = set()

        def dfs(node, par):
            if node in visited:
                return False

            visited.add(node)
            for nei in adj[node]:
                if nei == par:
                    continue
                if not dfs(nei, node):
                    visited.remove(node)
                    return False
            visited.remove(node)
            return True

        for node1, node2 in edges:
            adj[node1].append(node2)
            adj[node2].append(node1)
            if not dfs(node1, -1):
                return [node1, node2]

        return None
