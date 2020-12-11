/* Problem Statement
 *
 * Implement the int findMin(Node* rootNode) function, which will find the minimum value in a given Binary Search Tree. Remember, 
 * a Binary Search Tree is a Binary Tree that satisfies the following property. An illustration is also provided to jog your
 * memory.
 *
 * NodeValues(LeftSubtree) <= CurrentNodeValue < NodeValues(RightSubTree)
 *
 * Output
 *
 * Returns minimum integer value from a given binary search tree
 *
 * Sample Input 
 *
 * The root of an object of the BST class which contains data such as.
 * bst = { 
 * 6 -> 4, 9
 * 4 -> 2, 5
 * 9 -> 8, 12
 * 12 -> 10, 14
 * }
 *
 * where parent -> leftChild, rightChild
 *
 * Sample Output
 *
 * 2
 */

#include<iostream>

using namespace std;


class Node {
    
    public:
         
    int value;
    Node* leftChild;
    Node* rightChild;

    Node() {
        value = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    Node(int val) {
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class BinarySearchTree {
    
    public:

    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    BinarySearchTree(int value) {
        root = new Node(value);
    }

    Node* getRoot() {
        return root;
    }

    void insertBST(int value) {

        if (getRoot() == NULL) {
            root = new Node(value);
            return;
        }

        //starting from the root
        
        Node* currentNode = root;
        Node* parent;

        // while we get to the null node
        

        while (currentNode) {

            parent = currentNode; //update the parent

            if (value < currentNode -> value) {
                // if newValue < currentNode.val,
                // iterate to the left subtree

                currentNode = currentNode -> leftChild;
            }
            else {
                // if newValue >= currentNode.val,
                // iterate to the right subtree

                currentNode = currentNode -> rightChild;
            }
        }

        //by now, we will have the parent of the null
        //node where we have to insert the newValue

        if (value < parent -> value) {
            // if newValue < parent.val
            // insert into the leftChild

            parent -> leftChild = new Node(value);

        }

        else {

            // if newValue >= parent.val
            // insert into the rightChild

            parent -> rightChild = new Node(value);
        }
    }

};

int findMin(Node* rootNode) {

    if (rootNode == NULL)
       return -1; 

    while (rootNode -> leftChild != NULL)
        rootNode = rootNode -> leftChild;

    return rootNode -> value;
}


int main() {

    BinarySearchTree bsT(6);
    bsT.insertBST(3);
    bsT.insertBST(8);
    bsT.insertBST(12);
    bsT.insertBST(10);
    bsT.insertBST(14);
    cout << findMin(bsT.getRoot()) << endl;
    return 0;
}

// Your code here
