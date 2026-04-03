# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def helper (pre: int, inorderStart: int, inorderEnd: int) -> Optional[TreeNode]:
            if inorderStart > inorderEnd:
                return None
            
            inorderIndex = inorderStart
            while inorder[inorderIndex] != preorder[pre]:
                inorderIndex += 1

            head = TreeNode(preorder[pre])
            head.left = helper(pre + 1, inorderStart, inorderIndex - 1)
            head.right = helper(pre + inorderIndex - inorderStart + 1, inorderIndex + 1, inorderEnd)

            return head

        return helper(0, 0, len(inorder) - 1)