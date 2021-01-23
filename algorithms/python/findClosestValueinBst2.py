from BinarySearchTree import *

def findclosestvalueinbsthelper(current_node: Node, value: int, closest: int) -> int:

    if current_node == None:
        return closest

    if abs(value - current_node.data) < abs(value - closest):
        closest = current_node.data

    if value < current_node.data:
       return findclosestvalueinbsthelper(current_node.left, value, closest)

    else:
        return findclosestvalueinbsthelper(current_node.right, value, closest)

    return closest

def findclosestvalueinbst(tree: BinarySearchTree, value: int) -> int:
    return findclosestvalueinbsthelper(tree.head, value, abs(tree.head.data - value))

if __name__ == "__main__":

    tree = BinarySearchTree(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(2)
    tree.insert(5)
    tree.insert(13)
    tree.insert(22)
    tree.insert(1)
    tree.insert(14)

    value = 12
    print(findclosestvalueinbst(tree, value))
