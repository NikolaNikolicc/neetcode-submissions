from typing import Optional


class LRUCacheNode:
    def __init__(self, key: int = 0, val: int = 0, next  = None, prev = None):
        self.key = key
        self.val = val
        self.next = next
        self.prev = prev

class LRUCache:
    # head -> LRU element (least recently used)
    # tail -> MRU element (most recently used)
    def __init__(self, capacity: int):
        # set class attributes
        self.keyMap = {}
        self.capacity = capacity
        self.size = 0
        # set pointers
        self.head = LRUCacheNode()
        self.tail = LRUCacheNode()
        self.tail.prev = self.head
        self.head.next = self.tail

    def moveToTheFront(self, key: int) -> None:
        # get element
        elem = self.keyMap[key]
        # remove from list
        if (elem.next and elem.prev):
            elem.next.prev = elem.prev
            elem.prev.next = elem.next
        # put elem to the front
        self.tail.prev.next = elem
        elem.prev = self.tail.prev
        self.tail.prev = elem
        elem.next = self.tail

    def removeLRUElement(self) -> LRUCacheNode:
        # decrement size
        self.size -= 1
        # chain elements
        lruElem = self.head.next
        self.head.next = lruElem.next
        lruElem.next.prev = self.head
        lruElem.next = lruElem.prev = None
        return lruElem

    def get(self, key: int) -> int:
        if key in self.keyMap:
            self.moveToTheFront(key)
            return self.keyMap[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        node = None
        if key in self.keyMap:
            node = self.keyMap[key]
        else:
            # if not enough space remove lru element
            if self.size == self.capacity:
                lruElem = self.removeLRUElement()
                del self.keyMap[lruElem.key]
            # create and add element to hash map
            node = LRUCacheNode(key)
            self.keyMap[key] = node
            # increase size of hash map
            self.size += 1
        node.val = value
        self.moveToTheFront(key)