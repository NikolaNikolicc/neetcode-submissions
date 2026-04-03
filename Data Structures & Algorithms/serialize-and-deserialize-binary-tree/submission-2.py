# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        output = "#None#"

        queue = deque()
        queue.append(root)

        while queue:
            noneCnt = 0
            ln = len(queue)
            for _ in range(len(queue)):
                node = queue.popleft()
                if not node:
                    noneCnt += 1
                    output += str(None) + "#"
                    queue.append(None)
                    queue.append(None)
                else:
                    noneCnt = 0
                    output += str(node.val) + "#"
                    queue.append(node.left)
                    queue.append(node.right)

            if noneCnt == ln:
                break

            # print(output)
        return output
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        queue = data[1:-1].split("#")

        for i in range(len(queue) - 1, 0, -1):
            elem = queue[i]
            if elem == "None":
                continue
            node = TreeNode(elem)
            queue[i] = node

            if i*2 < len(queue) and queue[i*2] != "None":
                node.left = queue[i*2]
            else:
                node.left = None

            if i*2 + 1 < len(queue) and queue[i*2 + 1] != "None":
                node.right = queue[i*2 + 1]
            else:
                node.right = None

        return queue[1] if queue[1] != "None" else None