class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:

    def __init__(self, data):
        self.head = Node(data)

    def insert(self, item: int):

        levels = [self.head]
        while len(levels) != 0:

            level_size = len(levels)

            for i in range(level_size):

                current_node = levels[0]
                levels = levels[1: ]

                if current_node.left == None:
                    current_node.left = Node(item)
                    return

                else:
                    levels.append(current_node.left)

                if current_node.right == None:
                    current_node.right = Node(item)
                    return

                else:
                    levels.append(current_node.right)

        return
