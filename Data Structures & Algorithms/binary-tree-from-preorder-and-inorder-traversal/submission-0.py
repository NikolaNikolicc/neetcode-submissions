# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        hashInorder = {}

        for i in range(len(inorder)):
            # hashInorder[val] = position in array
            hashInorder[inorder[i]] = i

        readPreorder = 0
        def construct(start, end):
            nonlocal readPreorder

            if start > end or start > len(inorder) - 1 or end < 0:
                return None

            node = TreeNode(preorder[readPreorder])
            separator = hashInorder[preorder[readPreorder]]
            readPreorder += 1

            startLeft, endLeft = start, separator - 1
            startRight, endRight = separator + 1, end

            node.left = construct(startLeft, endLeft)
            node.right = construct(startRight, endRight)

            return node

        return construct(0, len(preorder) - 1)