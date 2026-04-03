# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def merge(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
            tmp = dummy = ListNode()
            while l1 and l2:
                if l1.val < l2.val:
                    dummy.next = l1
                    l1 = l1.next
                else:
                    dummy.next = l2
                    l2 = l2.next
                dummy = dummy.next
            if l1:
                dummy.next = l1
            if l2: 
                dummy.next = l2
            return tmp.next
        
        # inclusive
        def mergeSort(s: int, e: int) -> Optional[ListNode]:
            if s > e:
                return None
            if s == e:
                return lists[s]
            mid = (s + e) // 2
            left = mergeSort(s, mid)
            right = mergeSort(mid + 1, e)

            return merge(left, right)
            
        return mergeSort(0, len(lists) - 1)








