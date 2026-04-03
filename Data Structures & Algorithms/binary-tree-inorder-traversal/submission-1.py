# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        inorderTraversalResult = []

        def inorder(root: Optional[TreeNode]) -> None:
            if not root:
                return
            inorder(root.left)
            inorderTraversalResult.append(root.val)
            inorder(root.right)

        inorder(root)
        return inorderTraversalResult