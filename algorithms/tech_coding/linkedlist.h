#include<iostream>

using namespace std;

class Node {

    public:

        int value;
        Node* next;

        Node() {
            this -> value = 0;
            this -> next = nullptr;
        }

        Node(int value) {
            this -> value = value;
            this -> next = nullptr;
        }
};

class LinkedList {

    public:

        Node* head;

        LinkedList() {
            this -> head = nullptr;
        }

        LinkedList(int value) {
            this -> head = new Node(value);
        }

        void insertAtHead(int value) {

            Node* newNode = new Node(value);
            newNode -> next = head;
            head = newNode;
            return;
        }

        void insertAtTail(int value) {

            if (this -> head == nullptr) {
                insertAtHead(value);
                return;
            }

            Node* currentNode = this -> head;
            while (currentNode -> next != nullptr)
                currentNode = currentNode -> next;

            currentNode -> next = new Node(value);
            return;
        }
};

