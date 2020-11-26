/* Problem Statement
 *
 * Implement the Delete functionality. In this function, we will pass a particular value that we want to delete from the list. The
 * node containing this value could be anywhere on this list. It is also possible that such a node may not exist at all.
 *
 * Therefore, we could have to traverse the whole list until we find the value which needs to be deleted. If the value doesn't exist,
 * we do not need to do anything.
 *
 * Input
 *
 * A value to be deleted.
 *
 * Output
 *
 * true if the value is deleted, false otherwise.
 *
 * Sample Input
 *
 * 1 -> 2 -> 3 -> 4 -> 5
 * 4
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
            while (nthelement != nullptr) {
                cout << nthelement -> data << " ";
                nthelement = nthelement -> nextElement;
            }
            cout << endl;
            return;
        }

        bool Delete(int);
};

bool LinkedList::Delete(int value) {

    Node* previousElement = head;
    Node* nthelement = previousElement -> nextElement;

    if (previousElement -> data == value) {
        head = previousElement -> nextElement;
        return true;
    }

    while (nthelement != nullptr) {

        if (nthelement -> data == value) {
            previousElement -> nextElement = nthelement -> nextElement;
            delete nthelement;
            return true;
        }

        previousElement = previousElement -> nextElement;
        nthelement = nthelement -> nextElement;
    }
    return false;
} // end of delete()

int main() {

    LinkedList list;
    for (int i = 1; i <= 5; i++) {
        list.insertAtTail(i); // inserting value in list
        list.printList();
    }

    list.Delete(1); //calling delete function to delete 1
    list.printList();

    list.Delete(10); //calling delete function to delete 10
    list.printList();

    list.Delete(3); //calling delete function to delete 3
    list.printList();
    return 0;
}

























