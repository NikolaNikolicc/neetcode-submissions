# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        newHead = head
        nextElem = head.next
        head.next = None
        if nextElem:
            newHead = self.reverseList(nextElem)
            nextElem.next = head
        return newHead

