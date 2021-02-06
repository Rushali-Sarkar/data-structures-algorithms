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

        Node(int value) {

            data = value;
            nextElement = nullptr;
        }

};


class LinkedList {

    public:

        Node* head;
        int size;

        LinkedList() {
          head = nullptr;
        }

        LinkedList(int value) {
            size = 1;
            head = new Node(value);
        }

        Node* getHead() {
            return head;
        }

        int getSize() {
            return size;
        }

        void insertAtHead(int value) {

            if (getHead() == nullptr) {
                size = 1;
                head = new Node(value);
                return;
            }

            size++;
            Node* newNode = new Node(value);
            newNode -> nextElement = head;
            head = newNode;
            return;
        }

        string elements() {

            Node* currentNode = getHead();
            string result = "";
            while (currentNode -> nextElement != nullptr) {
                result = result + to_string(currentNode -> data) + " -> ";
                currentNode = currentNode -> nextElement;
            }

            result = result + to_string(currentNode -> data) + " -> " + "NULL";
            return result;
        }
};

                





