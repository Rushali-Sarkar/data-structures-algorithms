#include<iostream>
#include<iostream>
#include"BST.h"
#include<queue>

using namespace std;


void invertBinaryTree(BinarySearchTree& bst) {

    queue<Node*> nodes_to_be_inverted;
    nodes_to_be_inverted.push(bst.getRoot());
    Node* currentNode;
    Node* swapNode;
    int levelSize;

    while (!nodes_to_be_inverted.empty()) {

        levelSize = nodes_to_be_inverted.size();
        for (int i = 0; i < levelSize; i++) {

           currentNode = nodes_to_be_inverted.front();
           nodes_to_be_inverted.pop();
           if (currentNode -> leftChild != nullptr)
               nodes_to_be_inverted.push(currentNode -> leftChild);
           if (currentNode -> rightChild != nullptr)
               nodes_to_be_inverted.push(currentNode -> rightChild);

           swapNode = currentNode -> leftChild;
           currentNode -> leftChild = currentNode -> rightChild;
           currentNode -> rightChild = swapNode;
        }
    }
    return;
}
            



int main(int argc, char* argv[]) {

    BinarySearchTree bst(32);
    bst.insertBST(16);
    bst.insertBST(64);
    bst.insertBST(8);
    bst.insertBST(30);
    bst.insertBST(35);
    bst.insertBST(128);
    bst.insertBST(4);
    bst.insertBST(10);
    bst.insertBST(25);
    bst.insertBST(31);
    bst.insertBST(33);
    bst.insertBST(40);
    bst.insertBST(65);
    bst.insertBST(256);
    invertBinaryTree(bst);
    bst.showInOrder();
    return 0;
}
