class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parents = {}
        rank = {}
        for node1, node2 in edges:
            if node1 not in parents:
                parents[node1] = node1
                rank[node1] = 1
            if node2 not in parents:
                parents[node2] = node2
                rank[node2] = 1

        def find(node):
            cur = node
            while parents[cur] != cur:
                parents[cur] = parents[parents[cur]]
                cur = parents[cur]
            return cur

        def union(node1, node2):
            par1, par2 = find(node1), find(node2)

            if par1 == par2:
                return True
            elif rank[par1] < rank[par2]:
                parents[par1] = par2
                rank[par2] += rank[par1]
            else:
                parents[par2] = par1
                rank[par1] += rank[par2]
            return False

        for node1, node2 in edges:
            if union(node1, node2):
                return [node1, node2]

        return None
