/* Problem Statement
 *
 * In the findNth(int n) function, a certain n i specified as an argument. You simply need to return the node which is n spaces
 * away from the end of the linked list.
 *
 * Input
 *
 * A position n.
 *
 * Output 
 *
 * The value of the node n positions from the end. Returns -1 if n i out of bound.
 *
 * Sample Input
 * 
 * 22 -> 18 -> 60 -> 78 -> 47 -> 39 -> 99 and n = 3
 *
 * Sample Output
 *
 * 47
 */

#include<iostream>

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

        Node* head; // Pointing to start of the list

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
            if(isEmpty()) {
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

        int length() {
            Node* nthelement = head;
            int size = 0;
            while (nthelement !=  nullptr) {
                size++;
                nthelement = nthelement -> nextElement;
            }
            return size;
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

        int findNth(int n);
};


// To Find nth node from end of list
int LinkedList::findNth(int n) {
    
    int counter = 0;
    
    Node* forward = head;
    Node* current = head;

    while (forward -> nextElement != nullptr) {
        counter++;
        forward = forward -> nextElement;
        if (counter < n)
            continue;
        current = current -> nextElement;
    }

    return current -> data;
}

int main() {
    LinkedList list; // creating list
    for (int j = 0; j <= 7; j++) {
        list.insertAtHead(j); // inserting data in list
        list.printList();
    }
    int num = 5;
    int nth = list.findNth(num); // calling findNth function of list
    cout << num << "th element from end of the list : " << nth << endl;
    return 0;
}
