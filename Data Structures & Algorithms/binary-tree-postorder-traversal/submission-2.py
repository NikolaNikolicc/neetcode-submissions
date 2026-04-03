# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = [(root, False)]

        while stack:
            node, flag = stack.pop()
            if node:
                if not flag: # first
                    stack.append((node, True))
                    stack.append((node.right, False))
                    stack.append((node.left, False))
                else: # second
                    res.append(node.val)

        return res