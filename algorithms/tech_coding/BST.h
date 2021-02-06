#include<iostream>

using namespace std;

class Node {

    public:

        int value;
        Node* left;
        Node* right;

        Node() {
            this -> value = 0;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        Node(int value) {
            this -> value = value;
            this -> left = nullptr;
            this -> right = nullptr;
        }

};

class BinarySearchTree {

    public:

        Node* head;

        BinarySearchTree() {
            this -> head = new Node();
        }

        BinarySearchTree(int value) {
            this -> head = new Node(value);
        }

        void insert(int value) {

            if (this -> head == nullptr) {
               this -> head = new Node(value);
               return;
            }

            Node* parentNode = this -> head;
            Node* currentNode = this -> head;

            while (currentNode != nullptr) {

                parentNode = currentNode;

                if (value < currentNode -> value)
                    currentNode = currentNode -> left;

                else if (value >= currentNode -> value)
                    currentNode = currentNode -> right;
            }

            if (value < parentNode -> value)
                parentNode -> left = new Node(value);

            else if (value >= parentNode -> value)
                parentNode -> right = new Node(value);

            return;
        }

};



