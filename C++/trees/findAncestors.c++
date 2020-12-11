/* Problem Statement
 *
 * Implement the string findAncestors(Node* rootNode, int k) function, which will find the ancestors of the node whose value is "k".
 * Here rootNode is the root node of a binary search tree, and k is an integer value of node whose ancestors you need to find. An 
 * illustration is also given, your code is evaluated on the tree given in the example.
 *
 * Output
 *
 * Returns all the ancestors of k in the binary search tree in a string seperated by a comma.
 *
 * Sample Input
 *
 * bst = {
 *
 * 6 -> 4, 9
 * 4 -> 2, 5
 * 9 -> 8, 12
 * 12 -> 10, 14
 * }
 *
 * where parent -> leftChild, rightChild
 *
 * k = 10
 *
 * Sample Output
 *
 * 12, 9, 6
 */

#include<iostream>
#include<string>

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

        Node* rootNode;

        BinarySearchTree() {
            rootNode = new Node();
        }

        BinarySearchTree(int value) {
            rootNode = new Node(value);
        }
 
        Node* getRoot() {
            return rootNode;
        }

        Node* insert(Node* currentNode, int value) {

            if (currentNode == NULL) 
                return new Node(value);

            else if (currentNode -> value < value)
                currentNode -> rightChild = insert(currentNode -> rightChild, value);

            else
                currentNode -> leftChild = insert(currentNode -> leftChild, value);
            
            return currentNode;
        }

        void insertBST(int value) {

           if (getRoot() == NULL) {
                rootNode = new Node(value);
                return;
            }

         insert(rootNode, value);
        }

};

string findAncestors(Node* rootNode, int k) {

    string result;
    

    while (rootNode -> value != k) {

        if (k < rootNode -> value) { 
            result = to_string(rootNode -> value) + " " + result;
            rootNode = rootNode -> leftChild;
        }

        else {
            result = to_string(rootNode -> value) + " "+ result;
            rootNode = rootNode -> rightChild;
        }

        
    }

    return result;
}



string findAncestorsR (Node* rootNode, int k) {

    string result;

    if (rootNode -> value == k)
        return "";


    else if (rootNode -> value > k)
        return findAncestorsR(rootNode -> leftChild, k) + to_string(rootNode -> value) + " " + result;

    else
        return findAncestorsR(rootNode -> rightChild, k) + to_string(rootNode -> value) + " " + result;

    return to_string(rootNode -> value);
}



int main() {

    BinarySearchTree BST(6);
    BST.insertBST(1);
    BST.insertBST(133);
    BST.insertBST(12);

   cout << findAncestors(BST.getRoot(), 12) << endl;
   cout << findAncestorsR(BST.getRoot(), 12) << endl;
    return 0;
}
