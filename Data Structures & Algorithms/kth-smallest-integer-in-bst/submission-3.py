# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.glob = k
        def helper(root):
            if root:
                if self.glob > 0:
                    l = helper(root.left)
                    if l >= 0:
                        return l

                self.glob -= 1
                if not self.glob:
                    return root.val
                
                if self.glob > 0:
                    r = helper(root.right)
                    if r >= 0:
                        return r
            return -1
        return helper(root)