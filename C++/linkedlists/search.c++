/* To search for a specific value in a linked list, there is no other approach but to traverse the whole list until we find the
 * desired value. In that sense, the search operation in linked lists in similar to the linear search in normal arrays - all of them
 * take O(n) amount of time.
 *
 * The search algorithm in a linked list can be generalized to the following steps:
 *
 * 1. Start from the head node.
 *
 * 2. Traverse the list till you either find a node with the given value or you reach the end node, which will indicate that the 
 * given node doesn't exist in the list.
 *
 * Input 
 *
 * A value to be searched
 *
 * Output
 *
 * true if the value is found, false otherwise.
 *
 * Sample Input
 *
 * 5 -> 90 -> 10 -> 4
 * 4
 *
 *
 * Sample Output
 *
 * true
 */

#include<iostream>

using namespace std;

class Node {
    public: 
        int data; // Data to store (could be int, string object, etc)
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
        }

        void insertAtTail(int value) {
            if (isEmpty()) {
                insertAtHead(value);
            }

            else {

            Node* newNode = new Node(value);
            Node* last = head;
            while (last -> nextElement != nullptr)
                last = last -> nextElement;
            last -> nextElement = newNode;
            }
            return;
        }

       void printList() {

            Node* nthelement = head;
            while (nthelement  != nullptr) {
                cout << nthelement -> data << " ";
                nthelement = nthelement -> nextElement;
            }
            cout << endl;
            return;
        }
       bool search(int);

        
};

bool LinkedList::search(int value) {
    Node* nthelement = head;
    while (nthelement -> nextElement != nullptr) {
        if (nthelement -> data == value)
            return true;
        nthelement = nthelement -> nextElement; 
    }
    return false;
}

int main() {
    LinkedList list;
    srand(time(NULL)); // seed to produce random numbers everytime
    int num = 0;
    for (int i = 1; i < 6; i++) {
        num = rand() % 10 + 1; // generating random numbers in range 1 to 10
        list.insertAtTail(num);
        list.printList();
    }

    bool exist = false; // exsist it true only if element exists
    for (int j = 0; j < 5; j++) {
        num = rand() % 10 + 1;
        exist = list.search(num); // Calling search  function
        if (exist) { // only true if element exsists
            cout << num << " exists!" << endl;
        }
        else {
            cout << num << " does not exist!" << endl;
        }
    }
}
