/* You have to implement the findMid() function which is memeber function of a LinkedList and it should return the value of the
 * middle node. If the length of the list is even, the middle value will occur at, length / 2.
 * For a list of odd length, the middle value will be, length / 2 + 1.
 *
 * Input
 *
 * A linked list
 *
 * Output 
 *
 * The middle element of the linked list.
 *
 * Sample Input
 *
 * 7 -> 14 -> 10 -> 21 -> null
 *
 * Sample Output
 *
 * 14
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
        Node* head; // Pointing to start of the list.

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

        int length() {
            Node* nthelement = head;
            int size = 0;
            while (nthelement != nullptr) {
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

        int findMid();
};

int LinkedList::findMid() {
    Node* nthelement = head;
    int size = 0;
    while (nthelement != nullptr) {
        size++;
        nthelement = nthelement -> nextElement;
    }
    
    int mid = size / 2 + 1;
    if (size % 2 == 0)
        mid = size / 2;
    nthelement = head;
    size = 0;
    while (nthelement != nullptr) {
        size++;
        if (size == mid)
            return nthelement -> data;
        nthelement = nthelement -> nextElement;
    }
    return 0;

}

int main() {
    LinkedList list;
    srand (time(NULL)); // seed to produce random numbers everytime
    int num = 0;
    for (int i = 1; i <= 5; i++) {
        num = rand() % 10 + 1; // generating random numbers in range 1 to 100
        list.insertAtHead(num); //inserting value in the list
        list.printList();
    }

    int mid = list.findMid(); //calling findMid function
    cout << "Middle element of the list : " << mid << endl;
}
