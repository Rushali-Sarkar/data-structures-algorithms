/* Problem Statement
 *
 * Implement a function int findKthMax(Node* rootNode, int k, int nodes), which will take the root of a BST, any number "k" as an
 * input, and the total number of nodes in the tree. It will return kth maximum number from that tree.
 *
 * BST cannot have duplicate node values.
 *
 * Output
 *
 * Returns kth maximum value from the given tree
 *
 * Sample Input
 *
 * bst = {
 *  6 -> 4, 9
 *  4 -> 2, 5
 *  9 -> 8, 12
 *  12 -> 10, 14
 *  }
 *  where parent -> leftChild, rightChild
 *
 *  k = 3
 *
 *  Sample Output
 *
 *  10
 */

#include<iostream>

using namespace std;

class ArrayList {

    public:
        int capacity;
        int numElements;
        int front;
        int back;
        int* arr;

        ArrayList(int size) {
            capacity = size;
            numElements = 0;
            front = 0;
            back = capacity;
            arr = new int[capacity];
        }

        int getElements () {
            return numElements;
        }

        void push_front(int value) {

            if (front == back) {
                cout << "ArrayList is full" << endl;
                return;
            }

            arr[front++] = value;
            numElements++;
            return;
        }

        void push_back(int value) {

            if (back == front) {
                cout << "ArrayList is full" << endl;
                return;
            }

            arr[--back] = value;
            numElements++;
            return;
        }

        int pop_front() {

            if (front == 0 && back != 0) {

                cout << "The ArrayList is empty from front" << endl;
               return - 1;
            }

           numElements--;
           if (back == 0)
               return arr[back++];
           return arr[--front];
        }

        int pop_back() {

            if (front != capacity && back == capacity) {

                cout << "The ArrayList is empty from the back" << endl;
                return -1;
            }

            numElements--;
            if (front == capacity)
                return arr[--front];
            return arr[back++];
        }

        int getAt(int index) {
            return arr[index];
        }

        void showFront () {
             
            for (int i = 0; i < front; i++)
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }

        void showBack () {

            for (int i = back; i < capacity; i++)
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }

        void showList() {
            
            for (int i = 0; i < capacity; i++) 
                cout << arr[i] << '\t';
            cout << endl;
            return;
        }

};


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

        void insertBST(int value) {

            if (getRoot() == NULL) {
                rootNode = new Node(value);
                return;
            }

            Node* currentNode = rootNode;
            Node* parent;

            while (currentNode) {

                parent = currentNode;

                if (value < currentNode -> value)
                    currentNode = currentNode -> leftChild;

                else
                    currentNode = currentNode -> rightChild;
            }

            if (value < parent -> value)
                parent -> leftChild = new Node(value);
            else
                parent -> rightChild = new Node(value);
        }
};

void inOrderTraversal(Node* rootNode, ArrayList* result) {

    if (rootNode != NULL) {

        inOrderTraversal(rootNode -> leftChild, result);
        result -> push_front(rootNode -> value);
        inOrderTraversal(rootNode -> rightChild, result);

    }

    return;
}

int findKthMax(Node* rootNode, int k, int nodes) {
    ArrayList* inordertraversallist = new ArrayList(nodes);
    inOrderTraversal(rootNode, inordertraversallist);
    return inordertraversallist -> getAt(nodes - k);
}

int main() {

    BinarySearchTree bsT(6);
    bsT.insertBST(4);
    bsT.insertBST(9);
    bsT.insertBST(5);
    bsT.insertBST(2);
    bsT.insertBST(8);
    
    cout << findKthMax(bsT.getRoot(), 3, 6) << endl;
}


































