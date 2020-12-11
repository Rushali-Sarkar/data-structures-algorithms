#include<iostream>
#include"BST.h"
#include<limits.h>


using namespace std;

int helper(Node* rootNode, int element, int closest) {

    if (rootNode == nullptr)
        return closest;

    if (abs(rootNode -> value - element) < abs(rootNode -> value - closest))
        closest = rootNode -> value;

    if (rootNode -> value > element)
        return helper(rootNode -> leftChild, element, closest);

    else
        return helper(rootNode -> rightChild, element, closest);

    return closest;

    
}

int closestvalueBST(BinarySearchTree bst, int element) {
    return helper(bst.getRoot(), element, INT_MAX);
}

int main(int argc, char* argv[]) {

    BinarySearchTree bst(10);
    bst.insertBST(5);
    bst.insertBST(15);
    bst.insertBST(2);
    bst.insertBST(5);
    bst.insertBST(13);
    bst.insertBST(22);
    bst.insertBST(1);
    bst.insertBST(14);

    cout << closestvalueBST(bst, 25) << endl;
    return 0;
}

/* This algorithm takes a O(log(n)) time complexity in an average case to compute
 * and an O(log(n)) space complexity in an average case to compute since each time there is a function call
 * there are half as much things are stored in the call stack.
 * The worst case is however O(n) for both space and time complexity because the tree can be a straight vertical tree
 * without any branching and in that case we have to travel the entire tree without discardign anything at any point */



    
