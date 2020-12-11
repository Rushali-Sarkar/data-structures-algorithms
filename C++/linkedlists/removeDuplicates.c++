/*Problem Statement
 *
 * You will now be implementing the removeDuplicates() function. When a linked list is passed to this function, it removes any
 * node which is a duplicate of another existing node.
 *
 * Input 
 *
 * A linked list.
 *
 * Output
 *
 * A list with all the duplicates removed.
 *
 * Sample Input
 *
 * 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
 *
 * Sample Output
 *
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6
 */

#include<iostream>
#include<string>

using namespace std;

class Node {
    public:
        int data; // data to store (could be int, string object, etc)
        Node* nextElement; // Pointer to next element

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
        Node* head; // Pointing to the start of the list

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

        string elements() {

            string list = "";
            Node* start = head;
            while (start != nullptr) {
                list = list + to_string(start -> data) + " ";
                start = start -> nextElement;
            }

            return list;
        }

        void printList() {

            Node* nthElement = head;
            while (nthElement != nullptr) {
                cout << nthElement -> data << " ";
                nthElement = nthElement -> nextElement;
            }

            cout << endl;
            return;
        }

        string removeDuplicates();
};



string LinkedList::removeDuplicates() {

    Node* start = head;
    Node* next = new Node();
    Node* previous = new Node();

    while (start != nullptr) {
        previous = start;
        next = start -> nextElement;
        while (next != nullptr) {
            if (next -> data == start -> data) {
                Node* current = next -> nextElement;
                previous -> nextElement = next -> nextElement;
                delete next;
                next = current;
                continue;
            }
            previous = previous -> nextElement;
            next = next -> nextElement;
        }
        start = start -> nextElement;
    }

    return elements();
}

int main(){
     LinkedList list;
    for(int i = 1; i<4 ; i++) {
        list.insertAtHead(i);    // inserting value in the list
        list.printList();
    }
    list.insertAtHead(2);
    list.printList();  //after adding more elements
    list.insertAtHead(4);
    list.printList();  //after adding more elements
    list.insertAtHead(1);
    list.printList();  //after adding more elements
    
    string removeDuplicate = list.removeDuplicates(); // calling removeDuplicates function
    cout << "List after deleting duplicates from list :" << removeDuplicate <<endl;
    return 0;
}
