/* Problem Statement
 *
 * By definition, a loop is formed when a node in your linked list points to a previously traversed node.
 *
 * You must implement the detectLoop() function which will take a linked list as input and deduce whether or not a loop is present.
 *
 * Input
 *
 * A single linked list.
 *
 * Output
 *
 * Returns True if the given linked list contains a loop. Otherwise, it returns False.
 *
 * Sample Input
 *
 * 7 -> 14 -> 21 -> 7 // Both '7's are the same node. Not duplicates.
 *
 * Sample Output
 *
 * True
 */

#include<iostream>
#include<string>

using  namespace std;

class Node {
    public:
        int data; // data to store (could be int, string object, etc) 
        Node* nextElement; //Pointer to next element

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

    Node* head; // Pointing to start of the list.

    LinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtHead(int value) {
        Node* newnode = new Node(value);
        newnode -> nextElement = head;
        head = newnode;
        return;
    }

    void insertAtTail(int value) {
        if (isEmpty()){
            insertAtHead(value);
        }
        else {
            Node* newnode = new Node(value);
            Node* nthElement = head;
            while (nthElement -> nextElement != nullptr) 
                nthElement = nthElement -> nextElement;
            nthElement -> nextElement = newnode;
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

    string elements() {

       Node* fast = head;
       Node* slow = head;
       
       string list = "";
       while (fast != nullptr && fast -> nextElement != nullptr && fast -> nextElement -> nextElement != nullptr) {
           list = list + to_string(slow -> data) + " ";
           slow = slow -> nextElement;
           fast = fast -> nextElement -> nextElement;
           if (fast == slow) {
               list = list + to_string(slow -> data) + " ";
               slow = slow -> nextElement;
               while (slow != fast) {
                   list = list + to_string(slow -> data) + " ";
                   slow = slow -> nextElement;
               }
               list = list + to_string(fast -> data) + " ";
               return list;
           }
       }

       while (slow != nullptr) {
           list = list + to_string(slow -> data) + " ";
           slow = slow -> nextElement;
       }

        return list;
    }

    int length() {

        Node* nthelement = head;
        int size = 0;
        while (nthelement != nullptr) {
            size++;
            nthelement = nthelement -> nextElement;
        }

        return size;
    }

    void insertLoop() {

        int size = length();
        srand(time(NULL));
        int num = rand() % size;
        int counter = 0;

        Node* nthelement = head;
        Node* loopingelement = new Node();

        while (nthelement -> nextElement != nullptr) {
            counter++;
            if (counter == num)
                loopingelement = nthelement;
            nthelement = nthelement -> nextElement;
        }
        nthelement -> nextElement = loopingelement;
        if (loopingelement -> nextElement == nullptr) 
            nthelement -> nextElement -> nextElement = nthelement;
        return;
    }

    bool detectLoop();
};

bool LinkedList::detectLoop() {

    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast -> nextElement != nullptr && fast -> nextElement -> nextElement != nullptr) {
        fast = fast -> nextElement -> nextElement;
        slow = slow -> nextElement;
        if (fast == slow)
            return true;
    }

    return false;
}

int main() {
    LinkedList list;
    for (int i = 0; i <= 5; i++) {
        list.insertAtHead(i); //inserting value in the list
        list.printList();
    }

    list.insertLoop(); // generating a loop
    string listLoop = list.elements(); // printing list after creating loop
    cout << "List : " << listLoop << endl;
    bool checkLoop = list.detectLoop(); //calling detectLoop function
    cout << "Loop detected : " << checkLoop << endl;
    return 0;
}



