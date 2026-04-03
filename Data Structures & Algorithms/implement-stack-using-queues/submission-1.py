class MyStack:

    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int) -> None:
        self.q1.append(x)

    def helper(self, flag: bool) -> int:
        elem = None
        while len(self.q1):
            elem = self.q1.popleft()
            if len(self.q1) or flag:
                self.q2.append(elem)
        while len(self.q2):
            tmp = self.q2.popleft()
            self.q1.append(tmp)
        return elem

    def pop(self) -> int:
        return self.helper(False)

    def top(self) -> int:
        return self.helper(True)

    def empty(self) -> bool:
        return len(self.q1) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()