"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        newGraph = {}

        if not node:
            return None

        q = deque([node])
        newGraph[node] = Node(node.val)

        while q:

            for _ in range(len(q)):
                elem = q.popleft()

                for n in elem.neighbors:
                    if n not in newGraph:
                        newGraph[n] = Node(n.val)
                        q.append(n)
                    newGraph[elem].neighbors.append(newGraph[n])

        return newGraph[node]