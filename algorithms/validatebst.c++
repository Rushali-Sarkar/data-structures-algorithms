#include<iostream>
#include"BT.h"
#include<limits.h>

using namespace std;



bool is_in_correct_position(Node* currentNode, int maximum, int minimum) {

    if (currentNode == nullptr)
        return true;
    
    if (currentNode -> value < minimum || currentNode -> value >= maximum)
        return false;

    bool isLeftValid = is_in_correct_position (currentNode -> leftChild, currentNode -> value, minimum);
    bool isRightValid = is_in_correct_position (currentNode -> rightChild, maximum, currentNode -> value);

    return isLeftValid && isRightValid;
    
}

bool validateBST(BinaryTree bt) {

    int minimum = INT_MIN;
    int maximum = INT_MAX;

    return is_in_correct_position(bt.getRoot(), maximum, minimum);
}

int main(int argc, char* argv[]) {

    BinaryTree bt(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(2);
    bt.insert(5);
    bt.insert(13);
    bt.insert(22);
    bt.insert(1);
    bt.insert(3);

    cout << validateBST(bt) << endl;

    BinaryTree bt2(1);
    bt2.insert(2);
    bt2.insert(3);
    bt2.insert(4);
    bt2.insert(5);
    bt2.insert(6);
    bt2.insert(7);
    bt2.insert(8);

    cout << validateBST(bt2) << endl;

    return 0;

}
