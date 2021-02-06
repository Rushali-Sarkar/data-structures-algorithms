from BinarySearchTree import *

def findclosestvalueinBST(tree: BinarySearchTree, value: int) -> int:

    closest = (tree.head.data - value)
    current_node =  tree.head

    while current_node != None:

        if abs(current_node.data - value) < abs(closest - value):
            closest = current_node.data

        if value < current_node.data:
            current_node = current_node.left

        else:
            current_node = current_node.right

    return closest


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
    print(findclosestvalueinBST(tree, value))

