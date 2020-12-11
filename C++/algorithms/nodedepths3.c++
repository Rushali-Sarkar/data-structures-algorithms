#include<iostream>
#include"BT.h"

using namespace std;

int helper(Node* currentNode, int depth) {

    if (currentNode == nullptr)
        return 0;

    return depth + helper(currentNode -> leftChild, depth + 1) + helper(currentNode -> rightChild, depth + 1);

}

int nodedepths(BinaryTree bt) {

    return helper(bt.getRoot(), 0);
}

int main(int argc, char* argv[]) {

    BinaryTree bt(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);
    bt.insert(9);
    bt.insert(10);

    cout << nodedepths(bt) << endl;
    return 0;
}

/* O(n) time where n is nodes
 * O(h) space where h is height*/


