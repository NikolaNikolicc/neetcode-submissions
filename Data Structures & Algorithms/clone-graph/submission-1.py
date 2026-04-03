"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        if not node:
            return None

        visit = {}

        def dfs(node):
            copyNode = Node(node.val)
            visit[node] = copyNode

            for n in node.neighbors:
                if n not in visit:
                    copyNode.neighbors.append(dfs(n))
                else:
                    copyNode.neighbors.append(visit[n])

            return copyNode

        return dfs(node)