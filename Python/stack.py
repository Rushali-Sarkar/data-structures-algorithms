class Stack:

    def __init__(self, capacity: int):

        self.top = -1;
        self.stack_arr = [0 for i in range(capacity)];
        self.capacity = capacity;

    def push(self, item: int):

        if self.top == self.capacity - 1:
            print("Stack Overflow")
            return

        self.stack_arr[self.top + 1] = item
        self.top = self.top + 1
        return

    def pop(self) -> int:

        if self.top == -1:
            print("Stack Underflow")
            return -1

        item = self.stack_arr[self.top]
        self.top = self.top - 1
        return item

    def peek(self) -> int:

        if self.top == -1:
            return -1

        return self.stack_arr[top]
