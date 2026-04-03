class SegmentTreeNode:
    def __init__(self, L, R, val = 0):
        self.val = val
        self.left = None
        self.right = None
        self.L = L
        self.R = R

class SegmentTree:
    
    def __init__(self, nums: List[int]):

        def build(L, R):
            node = SegmentTreeNode(L, R)
            if L == R:
                node.val = nums[L]
                return node

            M = (R + L) // 2
            node.left = build(L, M)
            node.right = build(M + 1, R)
            node.val = node.left.val + node.right.val

            return node

        self.root = build(0, len(nums) - 1)
    
    def update(self, index: int, val: int) -> None:
        
        def setVal(node):
            M = (node.R + node.L) // 2
            if node.R == node.L:
                print(node.val)
                node.val = val
                return
            elif index <= M:
                setVal(node.left)
            else:
                setVal(node.right)
            node.val = node.left.val + node.right.val

        setVal(self.root)
    
    def query(self, L: int, R: int) -> int:

        def getSum(node):
            M = (node.R + node.L) // 2
            if node.L == node.R:
                return node.val
            elif L > M:
                return getSum(node.right)
            elif R <= M:
                return getSum(node.left)
            else:
                return getSum(node.left) + getSum(node.right)

        return getSum(self.root)










