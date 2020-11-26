/* Problem Statement
 * Union and intersection are two of the most popular operation which can be performed on data sets. Now, you will be implementing
 * them for linked lists! Let's take a look at their definitions:
 *
 * Union
 * 
 * Given two lists, A and B, the union is the list that contains elements or objects that belong to either A or to B or to both but
 * duplicates are not allowed.
 *
 * Intersection
 *
 * Given two lists, A and B, the intersection is the largest list which contains all the elements that are common to both the sets
 * but duplicates are not allowed.
 *
 * The Union(LinkedList list1, LinkedList list2) function takes two linked lists and returns their union.
 *
 * The Intersection(LinkedList list1, LinkedList list2) function takes two linked lists and returns all the elements that are
 * common between two linked lists.
 *
 * Input
 *
 * Two linked lists.
 *
 * Output
 *
 * -> A list contatining the union of the two lists.
 *  -> A list containing the intersection of the two lists.
 *
 * Sample Input
 *
 * 10 -> 20 -> 80 -> 20 -> 60 -> null
 * 15 -> 20 -> 30 -> 60 -> 60 -> 45 -> null
 *
 * Sample Output
 *
 * 10 -> 20 -> 80 -> 60 -> 15 -> 30 -> 45 -> null
 * 20 -> 60 -> null
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
        
        string removeDuplicates() {

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

        string Union(LinkedList list1, LinkedList list2);
        string Intersection(LinkedList list1, LinkedList list2);
};



string LinkedList::Union(LinkedList list1, LinkedList list2) {

   Node* start = list1.head;
   
   LinkedList unionelements;

   while (start != nullptr) {
       unionelements.insertAtHead(start -> data);
       start = start -> nextElement;
   }

   start = list2.head;
   while (start != nullptr) {
       unionelements.insertAtHead(start -> data);
       start = start -> nextElement;
   }

   unionelements.removeDuplicates();
   return unionelements.elements();

}

string LinkedList::Intersection(LinkedList list1, LinkedList list2) {

    list1.removeDuplicates();
    list2.removeDuplicates();

    Node* firstList = list1.head;
    Node* secondList = list2.head;

    LinkedList intersectionelements;

    while (firstList != nullptr) {

        int first = firstList -> data;

        while (secondList != nullptr) {

            int second = secondList -> data;
            
            if (first == second) {
                intersectionelements.insertAtHead(first);
                break;
            }

            secondList = secondList -> nextElement;
        }

        secondList = list2.head;
        firstList = firstList -> nextElement;
    }

    return intersectionelements.elements();
}
  


int main() {
  LinkedList list, list1;  // creating lists
  int rand_num = rand() % 5 + 1; 
  srand (time(NULL));

  cout << "List 1 " << endl;
  for(int i = 1; i<5 ; i++) {
    rand_num = rand() % 5 + 1;
    list.insertAtHead(rand_num);    // inserting value in the list
  }
  list.printList();

  cout << "List 2 " << endl;
  for(int i = 4; i<8 ; i++) {
    rand_num = rand() % 5 + 1;
    list1.insertAtHead(rand_num);    // inserting value in the list   
  }

  list1.printList();

  string check = list.Union(list , list1);  // calling union function
  cout << "Union List : "<< check << endl;

  string intersection = list.Intersection(list, list1); // calling intersection function
  cout << "Intersection List : " << intersection << endl;

  return 0;
}
