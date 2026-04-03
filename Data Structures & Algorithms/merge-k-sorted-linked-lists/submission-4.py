# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def merge(l1: List[Optional[ListNode]], l2: List[Optional[ListNode]]) -> Optional[ListNode]:
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
        
        
        if not len(lists):
            return None
            
        resultList = lists[0]
        for l in range(1, len(lists)):
            currList = lists[l]
            resultList = merge(resultList, currList)
        return resultList


