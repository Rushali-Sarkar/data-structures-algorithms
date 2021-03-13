#include<iostream>

using namespace std;


class Node {

    public:

        int data;
        Node* left;
        Node* right;

        Node() {
            this -> data = 0;
            this -> left = nullptr;
            this -> right = nullptr;
        }

        Node(int data) {
            this -> data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }

};


class BinarySearchTree {

    public:

        Node* head;

  
        BinarySearchTree(int data) {
            this -> head = new Node(data);
        }

        void insert(int data) {

            Node* current_node = this -> head;
            Node* parent_node = this -> head;

            while (current_node != nullptr) {

                parent_node = current_node;

                if (data < current_node -> data)
                    current_node = current_node -> left;

                else
                    current_node = current_node -> right;

            }

            if (data < parent_node -> data)
                parent_node -> left = new Node(data);

            else
                parent_node -> right = new Node(data);

            return;
        }

};
            
