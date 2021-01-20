class Node:

    def __init__(self, data: int):

        self.data = data
        self.next = None


class LinkedList:

    def __init__(self, data: int):

        self.head = Node(data)


    def insertAtHead(self, data: int):

        newNode = Node(data)
        self.head.next = newNode
        self.head = newNode

    def insertAtTail(self, data: int):

        if self.head == None:
            self.insertAtHead(data)
            return

        currentNode = self.head
        while currentNode.next != None:
            currentNode = currentNode.next

        currentNode.next = Node(data)
        return

