class Queue:

    def __init__(self, capacity: int):

        self.length = 0
        self.capacity = capacity
        self.head = 0
        self.tail = 0
        self.queue_arr = [0 for i in range(capacity)]

    def enqueue(self, item: int):

        if self.length == self.capacity:
            print("Queue Overflow")
            return

        if queue.tail == queue.capacity:
            queue.tail = 0

        self.queue_arr[self.tail] = item
        self.tail = self.tail + 1
        self.length = self.length + 1
        return

    def dequeue(self) -> int:

        if self.length == 0:
            print("Queue Underflow")
            return -1

        if self.head == self.capacity:
            self.head = 0

        item = self.queue_arr[self.head]
        self.head = self.head + 1
        self.length = self.length - 1

        return item

    def peek(self) -> int:
        
        if self.length == 0:
            return -1

        return self.queue_arr[self.head - 1]
