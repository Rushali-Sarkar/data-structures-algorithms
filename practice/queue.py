class Queue:

    def __init__(self, length = 0):
        self.length = length
        self.queue_arr = [-1 for i in range(self.length + 1)]
        self.head = 0
        self.tail = 0

    def isEmpty(self) -> bool:
        return self.head == self.tail

    def isFull(self) -> bool:
        if self.head == 0 and self.tail == self.length:
            return True
        return self.head == self.tail + 1

    def enqueue(self, element: int) -> None:
        if self.isFull():
            return None
        self.queue_arr[self.tail] = element
        self.tail += 1
        if self.tail == self.length + 1:
            self.tail = 0
        return None

    def dequeue(self) -> int:
        if self.isEmpty():
            return -1
        dequeue_element = self.queue_arr[self.head]
        self.head = self.head + 1
        if self.head == self.length + 1:
            self.head = 0
        return dequeue_element

    def peekHead(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue_arr[self.head]

    def peekTail(self) -> int:
        if self.isEmpty():
            return -1
        if self.tail == 0:
            return self.queue_arr[self.length]
        return self.queue_arr[self.tail - 1]

    def printQueue(self) -> None:
        if self.isEmpty():
            return None
        if self.head < self.tail:
            for i in range(self.head, self.tail):
                print(self.queue_arr[i], end = '\t')
            print()
            return None
        for i in range(self.head, self.length + 1):
            print(self.queue_arr[i], end = '\t')
        for i in range(0, self.tail):
            print(self.queue_arr[i], end = '\t')
        print()
        return None
