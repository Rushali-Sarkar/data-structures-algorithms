#include<iostream>

using namespace std;

class ListNode {

    public:

        int val;
        ListNode* next;

        ListNode() {
            val = 0;
            next = nullptr;
        }

        ListNode(int item) {
            val = item;
            next = nullptr;
        }

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        
        int digit1 = l1 == nullptr ? 0: l1 -> val;
        int digit2 = l2 == nullptr ? 0: l2 -> val;
        
        int sum = digit1 + digit2;
        int carry = sum / 10;
        int placevalue = sum % 10;
        
        ListNode* result = new ListNode(placevalue);
        ListNode* currentNode = result;
        
        l1 = l1 == nullptr ? nullptr : l1 -> next;
        l2 = l2 == nullptr ? nullptr : l2 -> next;
        
        while (l1 != nullptr || l2 != nullptr) {
            
            digit1 = l1 == nullptr ? 0: l1 -> val;
            digit2 = l2 == nullptr ? 0: l2 -> val;
            
            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            placevalue = sum % 10;
            
            currentNode -> next = new ListNode(placevalue);
            currentNode = currentNode -> next;
            
            l1 = l1 == nullptr ? nullptr : l1 -> next;
            l2 = l2 == nullptr ? nullptr : l2 -> next;
        
        }
        
        if (carry != 0)
            currentNode -> next = new ListNode(carry);
    
        return result;
    }

void show(ListNode* list) {

    while (list != nullptr) {
        cout << list -> val << '\t';
        list = list -> next;
    }

    cout << endl;
    return;
}

int main(int argc, char* argv[]) {

    ListNode* l1 = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);

    show(l1);
    show(l2);

    ListNode* result = addTwoNumbers(l1, l2);
    show(result);

    return 0;
}
