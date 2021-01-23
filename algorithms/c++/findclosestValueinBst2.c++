#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int findclosestvalueinbst_helper(Node* current_node, int target, int closest) {

    if (current_node == nullptr)
        return closest;

    if (abs(target - current_node -> data) < abs(closest - target)) 
        closest = current_node -> data;

    if (target < current_node -> data)
        return findclosestvalueinbst_helper(current_node -> left, target, closest);

    else if (target >= current_node -> data)
         return findclosestvalueinbst_helper(current_node -> right, target, closest); 

    return closest;
}

int findclosestvalueinbst(BinarySearchTree tree, int target) {
    return findclosestvalueinbst_helper(tree.head, target, abs(tree.head -> data - target));
}

int main(int argc, char* argv[]) {

    BinarySearchTree tree(10);
    tree.insert(15);
    tree.insert(5);
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


