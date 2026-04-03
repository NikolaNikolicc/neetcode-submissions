# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prevElem, currElem = None, head

        while currElem:
            nextElem = currElem.next
            currElem.next = prevElem
            prevElem = currElem
            currElem = nextElem
        return prevElem