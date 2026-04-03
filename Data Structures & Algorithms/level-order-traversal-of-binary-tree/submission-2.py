# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levelOrderTraversalList = []

        queue = deque()
        if root:
            queue.append(root)

        while queue:
            queueLength = len(queue)
            tmpList = []
            for i in range(queueLength):
                elem = queue.popleft()
                if elem.left: 
                    queue.append(elem.left)
                if elem.right: 
                    queue.append(elem.right)
                tmpList.append(elem.val)
            levelOrderTraversalList.append(tmpList)
            tmpList = []

        return levelOrderTraversalList