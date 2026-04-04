from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"{self.val} -> {self.next}"

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        def reverse(root:Optional[ListNode]) -> Optional[ListNode]:
            prev, curr = None, root

            while curr:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp
            return prev
        
        fast = slow = head

        while fast.next:
            slow = slow.next
            fast = fast.next
            if fast.next:
                fast = fast.next

        l2 = reverse(slow)
        l1 = head

        maxSum = 0
        while l2:
            maxSum = max(maxSum, l1.val + l2.val)
            l1 = l1.next
            l2 = l2.next

        return maxSum