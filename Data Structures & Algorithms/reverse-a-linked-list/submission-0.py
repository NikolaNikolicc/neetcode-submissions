# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return

        if not head.next:
            return head

        node = newHead = self.reverseList(head.next)
        while node.next:
            node = node.next
        node.next = head
        head.next = None
        return newHead