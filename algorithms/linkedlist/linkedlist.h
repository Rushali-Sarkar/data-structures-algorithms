#include<iostream>
#include<string.h>

using namespace std;

class Node {

    public:

        int data;
        Node* next;

        Node() {
            this -> data = 0;
            this -> next = nullptr;
        }

        Node(int data) {

            this -> data = data;
            this -> next = nullptr;
        }
};

class LinkedList: public Node {

    private:

        Node* head;

    public:

        LinkedList() {
            this -> head = nullptr;
        }

        LinkedList(int data) {
           this -> head = new Node(data);
        }

        Node* getHead() {
            return this -> head;
        }

        void insertAtHead(int data) {

            Node* headNode = this -> head;
            this -> head = new Node(data);
            this -> head -> next = headNode;
            return;
        }

        void insertAtTail(int data) {

            if (this -> head == nullptr) {
                this -> insertAtHead(data);
                return;
            }

            Node* currentNode = this -> head;

            while (currentNode -> next != nullptr)
                currentNode = currentNode -> next;

            currentNode -> next = new Node(data);
            return;
        }

        void remove(int data) {


            if (this -> head -> data == data) {
                
                Node* deleteNode = head; 
                this -> head = head -> next;
                delete deleteNode;
                return;
            }
            
            Node* previousNode = this -> head;
            Node* currentNode = this -> head -> next;

            while (currentNode != nullptr) {
                
                if (currentNode -> data == data) {

                    Node* deleteNode = currentNode;
                    previousNode -> next = currentNode -> next;
                    delete deleteNode;
                    return;
                }
                
                previousNode = previousNode -> next;
                currentNode = currentNode -> next;
            }

            return;
        }
                
        void print() {

            Node* currentNode = this -> head;
            while (currentNode != nullptr) {
                cout << currentNode -> data << " -> ";
                currentNode = currentNode -> next;
            }

            cout << "NULL" << endl;
            return;
        }
};
