#include<iostream>

using namespace std;

class Node {

    public:

        int value;
        Node* leftChild;
        Node* rightChild;

        Node() {
            value = 0;
            leftChild = nullptr;
            rightChild = nullptr;
        }

        Node(int val) {
            value = val;
            leftChild = nullptr;
            rightChild = nullptr;
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

        void insert(int value) {

            Node* currentNode = rootNode;
            Node* parentNode;

            while (currentNode != nullptr) {

                parentNode = currentNode;

                if (value < currentNode -> value) 
                    currentNode = currentNode -> leftChild;
                else
                    currentNode = currentNode -> rightChild;

            }

            if (value < parentNode -> value)
                parentNode -> leftChild = new Node(value);

            else
                parentNode -> rightChild = new Node(value);

            return;
        }

        bool search(int value) {

            Node* currentNode = rootNode;

            while (currentNode != nullptr) {

                if (currentNode -> value == value) 
                    return true;

                if (value < currentNode -> value)
                    currentNode = currentNode -> leftChild;

                else
                    currentNode = currentNode -> rightChild;
            }

            return false;
        }

        int getMinValue(Node* currentNode) {

            while (currentNode -> leftChild != nullptr) 
                currentNode = currentNode -> leftChild;

            return currentNode -> value;
        }

        void removeBST(int value, Node* currentNode, Node* parentNode = nullptr) {
           
            while (currentNode != nullptr) {

                if (currentNode -> value > value) {
                    parentNode = currentNode;
                    currentNode = currentNode -> leftChild;
                }

                else if (currentNode -> value < value) {
                    parentNode = currentNode;
                    currentNode = currentNode -> rightChild;
                }

                else {
                    if (currentNode -> leftChild != nullptr && currentNode -> rightChild != nullptr) {
                        currentNode -> value = getMinValue(currentNode -> rightChild);
                        removeBST(currentNode -> value, currentNode -> rightChild, currentNode);
                    }

                    else if (parentNode == nullptr) {

                        if (currentNode -> leftChild != nullptr) {
                            currentNode -> value = currentNode -> leftChild -> value;
                            currentNode -> rightChild = currentNode -> leftChild -> rightChild;
                            currentNode -> leftChild = currentNode -> leftChild -> leftChild;
                        }

                        else if (currentNode -> rightChild != nullptr) {

                            currentNode -> value = currentNode -> rightChild -> value;
                            currentNode -> leftChild = currentNode -> rightChild -> leftChild;
                            currentNode -> rightChild = currentNode -> rightChild -> rightChild;
                        }

                        else
                            rootNode = new Node();
                    }


                    else if (parentNode -> leftChild == currentNode) {

                        if (currentNode -> leftChild != nullptr)
                            parentNode -> leftChild = currentNode -> leftChild;

                        else
                            parentNode -> leftChild = currentNode -> rightChild;
                    }

                    else if (parentNode -> rightChild == currentNode) {

                        if (currentNode -> leftChild != nullptr) 
                            parentNode -> rightChild = currentNode -> leftChild;

                        else
                            parentNode -> rightChild = currentNode -> rightChild;
                    }
                    break;
                }
            }

            return;
        }

        void remove(int value) {
            removeBST(value, getRoot());
            return;
       }

        void inOrderTraversal(Node* currentNode) {
            
            if (currentNode == nullptr)
                return;

            inOrderTraversal(currentNode -> leftChild);
            cout << currentNode -> value << " ";
            inOrderTraversal(currentNode -> rightChild);
            return;
        }

};

int main(int argc, char* argv[]) {

    BinarySearchTree bst(100);
    bst.insert(56);
    bst.insert(200);
    bst.insert(48);
    bst.insert(75);
    bst.insert(150);
    bst.insert(321);

    bst.inOrderTraversal(bst.getRoot());
    cout << endl;
    bst.remove(56);
    bst.inOrderTraversal(bst.getRoot());
    cout << endl;
    bst.remove(100);
    bst.inOrderTraversal(bst.getRoot());
    cout << endl;
    return 0;

}
