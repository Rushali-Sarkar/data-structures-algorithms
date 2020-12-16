#include<iostream>

class Node {

    public:
        int data;
        Node* nextElement;

        Node(){
            data = 0;
            nextElement = nullptr;
        }

        Node(int item) {
            data = item;
            nextElement = nullptr;
        }
};

class LinkedList {

    private:
        Node* head;
        Node* tail;


