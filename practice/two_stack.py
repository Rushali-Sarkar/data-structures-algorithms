class TwoStack:

    def __init__(self, n = 0):
        self.n = n
        self.arr = [-1 for i in range(self.n)]
        self.top1 = -1
        self.top2 = self.n


    def isEmpty1(self) -> bool:
        return self.top1 == -1

    def isEmpty2(self) -> bool:
        return self.top2 == n

    def isFull(self) -> bool:
        return self.top2 == self.top1 + 1

    def push1(self, element) -> None:
        if not self.isFull():
            self.top1 += 1
            self.arr[self.top1] = element
            return None
        return None

    def push2(self, element) -> None:
        if not self.isFull():
            self.top2 -= 1
            self.arr[self.top2] = element
            return None
        return None

    def pop1(self) -> int:
        if not self.isEmpty1():
            pop_element = self.arr[self.top1]
            self.top1 -= 1
            return pop_element
        return -1

    def pop2(self) -> int:
        if not self.isEmpty2():
            pop_element = self.arr[self.top2]
            self.top2 += 1
            return pop_element
        return -1

    def peek1(self) -> int:
        if not self.isEmpty1():
            return self.arr[self.top1]
        return -1

    def peek2(self) -> int:
        if not self.isEmpty2():
            return self.arr[self.top2]
        return -1

    def print1(self) -> None:
        if not self.isEmpty1():
            for i in range(0, self.top1 + 1):
                print(self.arr[i], end = '\t')
            print()
            return None
        return None

    def print2(self) -> None:
        if not self.isEmpty2():
            for i in range(self.length - 1, self.top2 - 1, -1):
                print(self.arr[i], end = '\t')
            print()
            return None
        return None

