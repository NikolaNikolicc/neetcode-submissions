class MinHeap:
    
    def __init__(self):
        self.heap = [0]

    def push(self, val: int) -> None:
        self.heap.append(val)
        pos = len(self.heap) - 1

        while pos > 1 and self.heap[pos//2] > self.heap[pos]:
            tmp = self.heap[pos]
            self.heap[pos] = self.heap[pos//2]
            self.heap[pos//2] = tmp

            pos //= 2

    def pop(self) -> int:
        if len(self.heap) == 1:
            return -1

        if len(self.heap) == 2:
            return self.heap.pop()

        ret = self.heap[1]
        self.heap[1] = self.heap.pop()
        pos = 1
        while pos*2 < len(self.heap):
            if pos*2 + 1 < len(self.heap) and \
            self.heap[pos*2 + 1] < self.heap[pos*2] and \
            self.heap[pos*2 + 1] < self.heap[pos]:
                # swap right
                tmp = self.heap[pos*2 + 1]
                self.heap[pos*2 + 1] = self.heap[pos]
                self.heap[pos]  = tmp
                pos = pos*2 + 1
            elif self.heap[pos*2] < self.heap[pos]:
                # swap left
                tmp = self.heap[pos*2]
                self.heap[pos*2] = self.heap[pos]
                self.heap[pos] = tmp
                pos = pos*2
            else:
                break

        return ret

    def top(self) -> int:
        if len(self.heap) == 1:
            return -1

        return self.heap[1]

    def heapify(self, nums: List[int]) -> None:

        if not nums:
            return
        
        
        # append 0th position to the end
        nums.append(nums[0])

        self.heap = nums
        curr = (len(nums) - 1) // 2

        while curr > 0:
            pos = curr
            while pos*2 < len(self.heap):
                if pos*2 + 1 < len(self.heap) and \
                self.heap[pos*2 + 1] < self.heap[pos*2] and \
                self.heap[pos*2 + 1] < self.heap[pos]:
                    # swap right
                    tmp = self.heap[pos*2 + 1]
                    self.heap[pos*2 + 1] = self.heap[pos]
                    self.heap[pos]  = tmp
                    pos = pos*2 + 1
                elif self.heap[pos*2] < self.heap[pos]:
                    # swap left
                    tmp = self.heap[pos*2]
                    self.heap[pos*2] = self.heap[pos]
                    self.heap[pos] = tmp
                    pos = pos*2
                else:
                    break            
            curr -= 1




        
        