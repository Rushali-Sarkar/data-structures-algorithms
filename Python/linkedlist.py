class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None


    def insertAtHead(self, new_data):

        new_node = Node(new_data)
        new_node.next = self.head;
        self.head = new_node;


    def insertAtTail(self, new_data):

        if (self.head == None):
            insertAtTail(new_data)

        else:
            new_node = Node(new_data);
            current_node = self.head;

            while (current_node.next != None):
                current_node = current_node.next

            current_node.next = new_node

    def printList(self):

        current_node = self.head;

        while current_node != None:

            print(current_node.data)
            current_node = current_node.next





linkedlist = LinkedList()
linkedlist.insertAtHead(3)
linkedlist.insertAtHead(4)
linkedlist.insertAtHead(5)
linkedlist.insertAtTail(10)
linkedlist.printList()


