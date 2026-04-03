# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # if not head:
        #     return

        # if not head.next:
        #     return head

        # node = newHead = self.reverseList(head.next)
        # while node.next:
        #     node = node.next
        # node.next = head
        # head.next = None
        # return newHead

        def reverse(node):
            if not node:
                return None

            newHead = node
            if node.next:   
                newHead = reverse(node.next)
                node.next.next = node
            node.next = None
            return newHead

        return reverse(head)
            