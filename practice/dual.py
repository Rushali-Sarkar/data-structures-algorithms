class Queue:

    def __init__(self, length = 0):
        self.length = length
        self.head = 0
        self.tail = 0
        self.queue = [-1 for i in range(self.length + 1)]

    def isEmpty(self) -> bool:
        return self.head == self.tail

    def isFull(self) -> bool:
        if self.head == 0 and self.tail == self.length:
            return True
        return self.head == self.tail + 1

    def enqueue(self, element: int) -> None:
        if self.isFull():
            return None
        self.queue[self.tail] = element
        self.tail += 1
        if self.tail == self.length + 1:
            self.tail = 0
        return None

    def dequeue(self) -> int:
        if self.isEmpty():
            return -1
        pop_element = self.queue[self.head]
        self.head += 1
        if self.head == self.length + 1:
            self.head = 0
        return pop_element

    def getHead(self) -> int:
        if self.isEmpty():
            return -1
        return self.queue[self.head]

    def getTail(self) -> int:
        if self.isEmpty():
            return -1
        if self.tail == 0:
            return self.queue[self.length]
        return self.queue[self.tail - 1]

    def printQueue(self) -> None:
        if self.isEmpty():
            return None
        if self.head < self.tail:
            for i in range(self.head, self.tail):
                print(self.queue[i], end = '\t')
            print()
            return None
        for i in range(self.head, self.length + 1):
            print(self.queue[i], end = '\t')
        for i in range(0, self.tail):
            print(self.queue[i], end = '\t')
        print()
        return None

class Stack:

    def __init__(self, n = 0):
        self.n = n
        self.top = -1
        self.stack = [-1 for i in range(self.n)]

    def isEmpty(self) -> bool:
        return self.top == -1

    def isFull(self) -> bool:
        return self.top == self.n - 1

    def push(self, element: int) -> None:
        if self.isFull():
            return None
        self.top += 1
        self.stack[self.top] = element
        return None

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        pop_element = self.stack[self.top]
        self.top -= 1
        return pop_element

    def peek(self) -> int:
        if self.isEmpty():
            return -1
        return self.stack[self.top]
    
    def printStack(self) -> None:
        if self.isEmpty():
            return None
        for i in range(0, self.top + 1):
            print(self.stack[i], end = '\t')
        print()
        return None


class QueueUsingStack:

    def __init__(self, n = 0):
        self.stack1 = Stack(n)
        self.stack2 = Stack(n)
        self.n = n
        self.length = 0


    def isEmpty(self) -> bool:
        return self.length == 0

    def isFull(self) -> bool:
        return self.length == self.n

    def enqueue(self, element: int) -> None:
        if self.isFull():
            return None
        self.stack1.push(element)
        self.length += 1
        return None

    def dequeue(self) -> int:
        if self.isEmpty():
            return -1
        self.length -= 1
        if not self.stack2.isEmpty():
            return self.stack2.pop()
        while not self.stack1.isEmpty():
            self.stack2.push(self.stack1.pop())
        return self.stack2.pop()

class StackUsingQueue:

    def __init__(self, n = 0):
        self.n = n
        self.queue1 = Queue(self.n)
        self.queue2 = Queue(self.n)
        self.items = 0

    def isEmpty(self) -> bool:
        return self.items == 0

    def isFull(self) -> bool:
        return self.items == self.n

    def push(self, element: int) -> None:
        if self.isFull():
            return None
        self.items += 1
        if self.queue2.isEmpty():
            self.queue1.enqueue(element)
            return None
        self.queue2.enqueue(element)
        return None

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        last_element_popped = -1
        self.items -= 1
        if self.queue1.isEmpty():
            while not self.queue2.isEmpty():
                last_element_popped = self.queue2.dequeue()
                if self.queue2.isEmpty():
                    return last_element_popped
                self.queue1.enqueue(last_element_popped)
            return last_element_popped
        while not self.queue1.isEmpty():
            last_element_popped = self.queue1.dequeue()
            if self.queue1.isEmpty():
                return last_element_popped
            self.queue2.enqueue(last_element_popped)
        return last_element_popped