from BinaryTree import *

def branchsumshelper(current_node: Node, runningsum: int, sums: [int]):

    if current_node == None:
        return

    runningsum = runningsum + current_node.data

    if current_node.left == None and current_node.right == None:
        sums.append(runningsum)
        return

    branchsumshelper(current_node.left, runningsum, sums)
    branchsumshelper(current_node.right, runningsum, sums)

    return

def branchSums(tree: BinaryTree) -> [int]:

    sums = []
    branchsumshelper(tree.head, 0, sums)
    return sums

if __name__ == "__main__":

    tree = BinaryTree(1)
    tree.insert(2)
    tree.insert(3)
    tree.insert(4)
    tree.insert(5)
    tree.insert(6)
    tree.insert(7)
    tree.insert(8)
    tree.insert(9)
    tree.insert(10)

    sums = branchSums(tree)
    print(sums)
