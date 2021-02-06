#include <iostream>
#include <limits.h>
#include "BT.h"

using namespace std;

bool helper(Node* head, int lower, int upper) {

    if (head == nullptr)
        return true;

    int value = head -> value;
    if (value < lower || value >= upper)
       return false; 
    
    if (!helper(head -> right, value, upper))
       return false;
    
    if (!helper(head -> left, lower, value))
       return false;
    
    return true; 
}


bool isValidBST(BinaryTree tree) {
    return helper(tree.head, INT_MIN, INT_MAX);
}


int main(int argc, char* argv[]) {

    BinaryTree tree(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(4);
    tree.insert(4);
    tree.insert(7);

    cout << isValidBST(tree) << endl;
    return 0;
}

