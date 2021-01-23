#include<iostream>
#include"linkedlist.h"

using namespace std;

void deleteIndex(LinkedList* list, int index) {
   

    if (index == 0) {

        Node* deleteNode = list -> getHead();
        list -> getHead() = list -> getHead() -> next;
        delete deleteNode;
    }


    int index_count = 1;
    Node* currentNode = list -> getHead();
    Node* previousNode = currentNode;
    currentNode = currentNode -> next;

    while (currentNode != nullptr) {

        if (index_count == index) {
            Node* deleteNode = currentNode;
            previousNode -> next = currentNode -> next;
            delete deleteNode;
            return;
        }

        previousNode = previousNode -> next;
        currentNode = currentNode -> next;
        index_count++;
    }

    return;
}

int main(int argc, char* argv[]) {

    LinkedList list(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    deleteIndex(list, 2);
    deleteIndex(list, 0);

    list.print();

    return 0;
}



    
