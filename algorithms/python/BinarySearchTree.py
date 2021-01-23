class Node:

    def __init__(self, data):

        self.left = None
        self.right = None
        self.data = data


class BinarySearchTree:

    def __init__(self, data):

        self.head = Node(data)

    def insert(self, data):

        current_node = self.head
        parent_node = self.head

        while current_node != None:

            parent_node = current_node

            if data < current_node.data:
                current_node = current_node.left

            else:
                current_node = current_node.right

        if data < parent_node.data:
            parent_node.left = Node(data)

        else:
            parent_node.right = Node(data)

    def printTree(self):

        current_node = self.head
        nodes = [current_node]

        while (len(nodes) != 0):

            level_size = len(nodes)

            for i in range(level_size):

                print(nodes[i].data, end = " ")

                if nodes[i].left != None:
                    nodes.append(nodes[i].left)

                if nodes[i].right != None:
                    nodes.append(nodes[i].right)
            
            nodes = nodes[level_size:]
            print()                
