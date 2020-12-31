class Stack:

    def __init__(self, capacity: int):

        self.top = -1;
        self.stack_arr = [];
        self.capacity = capacity;

    def push(self, item: int):

        if self.top == self.capacity - 1:
            print("Stack Overflow")
            return

        self.stack_arr.append(item)
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

    def size(self) -> int:
        return self.top + 1
