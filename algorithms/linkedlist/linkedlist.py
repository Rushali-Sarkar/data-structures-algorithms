class Node:

    def __init__(self, data: int):

        self.data = data;
        self.next = None;


class LinkedList(Node):

    def __init__(self, data: int):

        self.head = Node(data)

    def insertAtHead(self, item: int):

        headNode = self.head
        self.head = Node(item)
        self.head.next = headNode

        return

    def insertAtTail(self, item: int):

        if self.head == None:
            self.insertAtHead(item)
            return

        currentNode = self.head
        while currentNode.next != None:
            currentNode = currentNode.next

        currentNode.next = Node(item)

        return

    def remove(self, item: int):

        if self.head.data == item:

            self.head = self.head.next
            return

        previousNode = self.head
        currentNode = self.head.next

        while currentNode != None:

            if currentNode.data == item:

                previousNode.next = currentNode.next
                return

            previousNode = previousNode.next
            currentNode = currentNode.next

        return

    def printList(self):

        currentNode = self.head

        while currentNode != None:

            print(currentNode.data, end = " -> ")
            currentNode = currentNode.next

        print("NULL")

        return
