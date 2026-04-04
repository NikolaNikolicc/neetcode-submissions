"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        # key: origigi, val: cloned node
        clones = {}

        def helper(node):
            if not node:
                return None
            
            if node not in clones:
                clones[node] = Node(node.val)
                for nei in node.neighbors:
                    clonedNeighbor = helper(nei)
                    clones[node].neighbors.append(clonedNeighbor)

            return clones[node]
        
        return helper(node)