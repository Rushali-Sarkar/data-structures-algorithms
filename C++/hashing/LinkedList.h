#include<iostream>
#include<string>

using namespace std;


class Node {

    public:

        int data;
        Node* nextElement;

        Node() {
            data = 0;
            nextElement = nullptr;
        }

        Node(int item) {
            data = item;
            nextElement = nullptr;
        }
};

class LinkedList {

    public:

        Node* head;
        
        LinkedList() {
            head = nullptr;
        }

        LinkedList(int item) {
            head = new Node(item);
        }

        void insertAtHead(int item) {

            Node* newNode = new Node(item);
            newNode -> nextElement = head;
            head = newNode;
            return;
        }

        void insertAtTail(int item) {

            if (head == nullptr) {
                head = new Node(item);
                return;
            }

            Node* currentNode = head;
            while (currentNode -> nextElement != nullptr)
                currentNode = currentNode -> nextElement;

            currentNode -> nextElement = new Node(item);
            return;
        }

        Node* getHead() {
            return head;
        }

        string elements() {

            string list = "";

            Node* currentNode = head;
            while (currentNode -> nextElement != nullptr){ 
                list = list + to_string(currentNode -> data) + " -> ";
                currentNode = currentNode -> nextElement;
            }

            list = list + to_string(currentNode -> data) + " -> " + "NULL";
            return list;
        }

        void printList() {

            Node* currentNode = head;
            while (currentNode != nullptr) {
                cout << currentNode -> data << " ";
                currentNode = currentNode -> nextElement;
            }

            cout << endl;
        }
};

