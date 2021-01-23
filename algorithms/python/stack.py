class Stack:

    def __init__(self, capacity: int):

        self.capacity = capacity
        self.stack_arr = [0 for i in range(capacity)]
        self.top = -1


    def isEmpty(self) -> bool:
        return self.top == -1
        
    def push(self, item: int):

        if self.top == self.capcaity - 1:
            print("Stack Overflow")
            return

        self.top += 1
        self.stack_arr[self.top] = item
        return

    def pop(self) -> int:

        if self.top == -1:
            print("Stack Underflow")
            return -1


        item = self.stack_arr[self.top]
        self.top -= 1
        return item

    def front(self) -> int:
        return self.stack_arr[self.top]


if __name__ == "__main__":
    print("This is main")
 
