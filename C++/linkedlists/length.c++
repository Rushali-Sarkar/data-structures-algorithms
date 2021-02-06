/* Problem Statement
 *
 * In this problem, you have to implement the length() function which will find the length of a given linked list.
 *
 * Input 
 *
 * A linked list.
 *
 * Sample Input
 *
 * 0 -> 1 -> 2 -> 3 -> 4
 *
 * Sample Output
 *
 * 5
 */

#include<iostream>

using namespace std;

class Node {

    public:
        int data; // data to store (could be int, string object, etc)
        Node* nextElement; // Pointer to next Element

        Node() {
            //Constructor to initialize nextElement of newly created node.
            nextElement = nullptr;
        }

        Node(int value) {
            data = value;
            nextElement = nullptr;
        }
};

class LinkedList {

    public:
        Node* head; // pointing to start of the list

        LinkedList() {
            head = nullptr;
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void insertAtHead(int value) {
            Node* newNode = new Node(value);
            newNode -> nextElement = head;
            head = newNode;
            return;
        }

        void insertAtTail(int value) {

            if (isEmpty()) {
                insertAtHead(value);
            }

            else {
                Node* newNode = new Node(value);
                Node* nthelement = head;
                while (nthelement -> nextElement != nullptr)
                    nthelement = nthelement -> nextElement;
                nthelement -> nextElement = newNode;
            }
            return;
        }

        void printList() {
            Node* nthelement = head;
            while (nthelement != nullptr) {
                cout << nthelement -> data << " ";
                nthelement = nthelement -> nextElement;
            }
            cout << endl;
            return;
        }

        int length();
};

int LinkedList::length() {
    int size = 0;
    Node* nthelement = head;
    while (nthelement != nullptr) {
        nthelement = nthelement -> nextElement;
        size++;
    }
    return size;
}

int main() {
    LinkedList list; // created linked list
    for (int i = 1; i <= 8; i++) {
        list.insertAtHead(i); // inserting data in list
        list.printList();
    }

    int listlength = list.length(); // calling length function
    cout << "Length of the list is " << listlength << " ! " << endl;
    return 0;
}
    
