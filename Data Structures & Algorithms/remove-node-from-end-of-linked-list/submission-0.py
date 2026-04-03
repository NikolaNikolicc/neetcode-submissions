# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast, slow = head, head

        cpy = 0
        while cpy < n:
            fast = fast.next
            cpy += 1

        prev = ListNode()
        
        while fast:
            fast = fast.next
            prev = slow
            slow = slow.next

        prev.next = slow.next
        if head == slow:
            head = slow.next
        slow.next = None

        return head