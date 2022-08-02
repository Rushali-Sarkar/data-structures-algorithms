class Deque:

    def __init__(self, length = 0):
        self.head = 0
        self.tail = 0
        self.length = length
        self.arr = [-1 for i in range(self.length + 1)]

    
    def isEmpty(self) -> bool:
        return self.head == self.tail

    def isFull(self) -> bool:
        if self.head == 0 and self.tail == self.length:
            return True
        return self.head == self.tail + 1

    def pushTail(self, element: int) -> None:
        if not self.isFull():
            self.arr[self.tail] = element
            self.tail += 1
            if self.tail == self.length + 1:
                self.tail = 0
            return None
        return None

    def pushHead(self, element: int) -> None:
        if not self.isFull():
            if self.head == 0:
                self.head = self.length
            else:
                self.head -= 1
            self.arr[self.head] = element
            return None
        return None

    def popTail(self) -> int:
        if self.isEmpty():
            return -1
        if self.tail == 0:
            pop_element = self.arr[self.length]
            self.tail = self.length
            return pop_element
        pop_element = self.arr[self.tail - 1]
        self.tail -= 1
        return pop_element
    
    def popHead(self) -> int:
        if self.isEmpty():
            return -1
        pop_element = self.arr[self.head]
        if self.head == self.length:
            self.head = 0
        else:
            self.head += 1
        return pop_element

    def peekHead(self) -> int:
        if not self.isEmpty():
            return self.arr[self.head]
        return -1

    def peekTail(self) -> int:
        if not self.isEmpty():
            if self.tail == 0:
                return self.arr[self.length]
            return self.arr[self.tail - 1]
        return -1

    def printDeque(self) -> None:
        if not self.isEmpty():
            if self.head < self.tail:
                for i in range(self.head, self.tail):
                    print(self.arr[i], end = '\t')
                print()
                return None
            for i in range(self.head, self.length + 1):
                print(self.arr[i], end = '\t')
            for i in range(0, self.tail):
                print(self.arr[i], end = '\t')
            print()
            return None
        return None

