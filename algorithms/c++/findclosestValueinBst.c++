#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int findclosestvalueinbst(BinarySearchTree tree, int target) {

    Node* current_node = tree.head;
    int closest = current_node -> data;

    while (current_node != nullptr) {

        if (abs(current_node -> data - target) < abs(closest - target))
            closest = current_node -> data;

        if (target < current_node -> data) 
            current_node = current_node -> left;

        else
            current_node = current_node -> right;
    }

    return closest;
}

int main(int argc, char* argv[]) {

    BinarySearchTree tree(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(5);
    tree.insert(13);
    tree.insert(22);
    tree.insert(1);
    tree.insert(14);

    int target = 12;

    cout << findclosestvalueinbst(tree, target) << endl;
    return 0;
}


