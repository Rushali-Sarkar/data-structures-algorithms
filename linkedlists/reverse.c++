/* Problem Statement
 *
 * You have to write the reverse function, which starts iterating from the head and swap nodes of the list, such that, in the end,
 * it returns a string that contains reversed list.
 *
 * Input
 *
 * A linked list.
 *
 * Output
 *
 * The reversed linked list.
 *
 * Sample Input
 *
 * 0 -> 1 -> 2 -> 3 -> 4
 *
 * Sample Output
 *
 * 4 -> 3 -> 2 -> 1 -> 0
 */

#include<iostream>
#include<string>

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

        string elements() {
            Node* nthelement = head;
            string list = "";
            while (nthelement != nullptr) {
                list = list + to_string(nthelement -> data) + " ";
                nthelement = nthelement -> nextElement;
            }
          return list;
        }
    
       string reverse();
       
};

string LinkedList::reverse() {

  

    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current -> nextElement;
        current -> nextElement = previous;
        previous = current;
        current = next;
    }
    
    head = previous;

    return elements();
}
   

int main() {
    LinkedList list; // creating list
    for (int j = 1; j <= 7; j++) {
        list.insertAtHead(j); //inserting data in list
        list.printList();
    }

    string reversed = list.reverse(); // calling  reverse  function of list
    cout << "List after reverse function : " << reversed << endl;
    return 0;
}





