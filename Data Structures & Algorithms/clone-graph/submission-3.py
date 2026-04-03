"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        clones = {}
        def cloneNode(root):
            if root in clones:
                return clones[root]
            
            n = Node(root.val, None)
            clones[root] = n
            for nei in root.neighbors:
                clone = cloneNode(nei)
                clones[root].neighbors.append(clone)

            return clones[root]

        return cloneNode(node) if node else None
        