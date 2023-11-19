class Stack:

    def __init__(self, n = 0):
        self.top = -1
        self.n = n
        self.min_stack = [-1 for i in rnage(self.n)]
        self.stack_arr = [-1 for i in range(self.n)]
        self.current_min = float('inf')

    def isEmpty(self) -> None:
        return self.top == -1

    def isFull(self) -> None:
        return self.top == self.n - 1
    
    def push(self, element: int) -> None:
        if self.isFull():
            return None
        self.top += 1
        self.stack_arr[self.top] = element
        self.current_min = min(element, self.current_min)
        self.min_stack[self.top] = min(element, self.current_min)
        return None

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        pop_element = self.stack_arr[self.top]
        self.top -= 1
        if self.isEmpty():
            self.current_min = float('inf')
        else:
            self.current_min = self.stack_arr[self.top]
        return pop_element

    def peek(self) -> int:
        if self.isEmpty():
            return -1
        return self.stack_arr[self.top]

    def getMin(self) -> int:
        return self.current_min

    def printStack(self) -> None:
        for i in range(self.top + 1):
            print(self.stack_arr[i], end = '\t')
        print()
        return None
