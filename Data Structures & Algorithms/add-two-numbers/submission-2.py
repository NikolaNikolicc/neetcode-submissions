# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = start = ListNode()
        carry = 0
        while l1 or l2 or carry:
            num = carry

            if not l1 and not l2:
                pass
            elif not l1:
                num += l2.val
                l2 = l2.next
            elif not l2:
                num += l1.val
                l1 = l1.next
            else:
                num += l1.val + l2.val
                l1 = l1.next
                l2 = l2.next

            dummy.next = ListNode(num % 10) 
            dummy = dummy.next
            carry = num // 10
            
        return start.next
            