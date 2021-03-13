/* Just as heads and tails are polar opposites, this function is opposite of what we saw in the last lesson. However, it is just as
 * simple.
 *
 * We need to insert a new object at the end of the linked list. You can naturally guess, that this newly added node will point
 * to NULL as it is at the tail.
 *
 * Now that we've understood the theory, it's time for you to write the practical implementation. In the code provided below, you
 * must complete the insertAtTail() function.
 *
 * It will take an integer as an input parameter and insert a node contatining that value at the end of the list.
 *
 * Input
 *
 * An integer value
 *
 * Output
 * 
 * The updated linked list with the value inserted.
 *
 * Sample Input
 *
 * 0 -> 1 -> 2
 *
 * 3
 *
 * Sample Output
 *
 * 0 -> 1 -> 2 -> 3
 *
 */

#include<iostream>

using namespace std;

class Node {
    public: 
        int data; // Data to store (could be int, string object, etc)
        Node* nextElement; // Pointer to next element

        Node() {
            //Constructor to initialize nextElement of newly created node.
            nextElement = nullptr;
        }

        Node (int value) {
            data = value;
            nextElement = nullptr;
        }
};

class LinkedList {
    public:
        Node* head; //pointing to start of the list
       
        LinkedList() {
            head = nullptr;
        }

       void insertAtTail(int);

       void insertAtHead(int value) {
           Node* newNode = new Node(value);
           newNode -> nextElement = head;
           head = newNode;
           return;
       }

       bool isEmpty() {
           return head == nullptr;
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
};

//Inserts a vlaue at the end of the list

void LinkedList::insertAtTail(int value) {

        if (isEmpty()) {
            insertAtHead(value);
        }

        else {
    
        Node* newNode = new Node(value);
        Node* last = head;
        while(last -> nextElement != nullptr)
            last = last -> nextElement;
        last -> nextElement = newNode;
        }
    return;
}

int main() {
    LinkedList list;
    srand(time(NULL)); // seed to produce random numbers everytime
    int num = 0;
    for (int i = 1; i < 6; i++) {
        num = rand() % 10 + 1; //generating random numbers in range 1 to 10
        list.insertAtTail(num); // inserting value at the tail of the list
        list.printList();
    }
}
