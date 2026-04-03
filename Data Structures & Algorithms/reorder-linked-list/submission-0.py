# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        

        def reverse(node):
            if not node:
                return None

            newHead = node
            if node.next:   
                newHead = reverse(node.next)
                node.next.next = node
            node.next = None
            return newHead

        fast, slow = head.next, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next
            fast = fast.next

        bigger = reverse(slow.next)
        slow.next = None
        lower = head.next
        l = False
        curr = head
        
        while bigger:
            if l:
                # print(lower.val)
                curr.next = lower
                lower = lower.next
            else:
                # print(bigger.val)
                curr.next = bigger
                bigger = bigger.next
            l = not l
            curr = curr.next

        if lower:
            curr.next = lower
    