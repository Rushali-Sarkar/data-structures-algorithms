#include<iostream>
#include"LinkedList.h"

using namespace std;


LinkedList sort(LinkedList list) {

    Node* currentNode = list.getHead();

    while (currentNode != nullptr) {

        Node* nextNode = currentNode -> nextElement;
        int smallest = currentNode -> data;
        Node* smallestNode = currentNode;

        while (nextNode != nullptr) {
            if (nextNode -> data < smallest) { 
                smallest = nextNode -> data;
                smallestNode = nextNode;
            }

            nextNode = nextNode -> nextElement;
        }
        
        smallestNode -> data = currentNode -> data;
        currentNode -> data = smallest;

        currentNode = currentNode -> nextElement;

  }
    return list;
}
      

int main(int argc, char* argv[]) {

    LinkedList list;
    list.insertAtHead(1);
    list.insertAtHead(22);
    list.insertAtHead(12);
    list.insertAtHead(21);
    list.insertAtHead(9);
    list.insertAtHead(40);
    list.insertAtHead(92);
    list.insertAtHead(86);

    string result = list.elements();
    cout << result << endl;

    list = sort(list);
    string sorted = list.elements();
    cout << sorted << endl;

    return 0;
}

