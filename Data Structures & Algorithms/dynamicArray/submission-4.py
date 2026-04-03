class DynamicArray:
    
    def __init__(self, capacity: int):
        self.arr = [0]*capacity
        self.capacity = capacity
        self.curr = 0

    def get(self, i: int) -> int:
        return self.arr[i]

    def set(self, i: int, n: int) -> None:
        self.arr[i] = n

    def pushback(self, n: int) -> None:
        if self.curr + 1 > self.capacity:
            self.resize()
        self.arr[self.curr] = n
        self.curr += 1   

    def popback(self) -> int:
        self.curr -= 1
        return self.arr[self.curr]

    def resize(self) -> None:
        tmp = self.arr[:]
        self.capacity *= 2
        self.arr = [0]* self.capacity
        for i in range(len(tmp)):
            self.arr[i] = tmp[i]

    def getSize(self) -> int:
        return self.curr
    
    def getCapacity(self) -> int:
        return self.capacity