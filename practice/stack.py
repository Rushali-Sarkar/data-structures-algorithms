class Stack:

    def __init__(self, n = 0):
        self.top = -1
        self.n = n
        self.stack_arr = [-1 for i in range(self.n)]

    def isEmpty(self) -> None:
        return self.top == -1

    def isFull(self) -> None:
        return self.top == self.n - 1
    
    def push(self, element: int) -> None:
        if self.isFull():
            return None
        self.top += 1
        self.stack_arr[self.top] = element;
        return None

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        pop_element = self.stack_arr[self.top]
        self.top -= 1
        return pop_element

    def peek(self) -> int:
        if self.isEmpty():
            return -1
        return self.stack_arr[self.top]

    def printStack(self) -> None:
        for i in range(self.top + 1):
            print(self.stack_arr[i], end = '\t')
        print()
        return None
