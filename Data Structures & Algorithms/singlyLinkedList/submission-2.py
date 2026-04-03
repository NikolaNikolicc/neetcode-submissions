class Node:

    def __init__(self, val = 0):
        self.val = val
        self.next = None

class LinkedList:
    
    def __init__(self):
        self.head = Node()
        self.tail = self.head
    
    def get(self, index: int) -> int:
        curr = self.head.next
        while curr and index > 0:
            curr = curr.next
            index -= 1

        if not curr:
            return -1

        return curr.val

    def insertHead(self, val: int) -> None:
        node = Node(val)
        node.next = self.head.next
        self.head.next = node
        if self.tail == self.head:
            self.tail = node

    def insertTail(self, val: int) -> None:
        self.tail.next = Node(val)
        self.tail = self.tail.next     


    def remove(self, index: int) -> bool:
        prev = self.head
        while prev and prev.next and index > 0:
            prev = prev.next
            index -= 1

        if not prev or not prev.next:
            return False

        if prev.next == self.tail:
            self.tail = prev
            
        prev.next = prev.next.next
        return True

    def getValues(self) -> List[int]:
        arr = []
        curr = self.head.next
        while curr:
            arr.append(curr.val)
            curr = curr.next

        return arr
        
