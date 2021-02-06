#include <iostream>
#include "linkedlist.h"

using namespace std;

void show(LinkedList list) {

    Node* currentNode = list.head;

    while (currentNode != nullptr) {
        cout << currentNode -> value << " -> ";
        currentNode = currentNode -> next;
    }

    cout << "NULL" << endl;
    return;
}


LinkedList add(LinkedList number1, LinkedList number2) {

    LinkedList result;
    Node* currentdigit1 = number1.head;
    Node* currentdigit2 = number2.head;
    int val = 0;
    int carry = 0;

    while (currentdigit1 != nullptr || currentdigit2 != nullptr) {


        int digit1 = currentdigit1 == nullptr ? 0 : currentdigit1 -> value;
        int digit2 = currentdigit2 == nullptr ? 0 : currentdigit2 -> value;

        val = (digit1 + digit2 + carry) % 10;
        carry = (digit1 + digit2 + carry) / 10;

        result.insertAtTail(val);

        currentdigit1 = currentdigit1 == nullptr ? nullptr : currentdigit1 -> next;
        currentdigit2 = currentdigit2 == nullptr ? nullptr : currentdigit2 -> next;
    }

    if (carry != 0)
        result.insertAtTail(carry);

    return result;
}


int main(int argc, char* argv[]) {

    LinkedList number2(9);
    number2.insertAtHead(4);
    number2.insertAtHead(4);

    LinkedList number1(4);
    number1.insertAtHead(6);

    LinkedList result = add(number1, number2);

    show(number1);
    show(number2);
    show(result);

    return 0;


}




