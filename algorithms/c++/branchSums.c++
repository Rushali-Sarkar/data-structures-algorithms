#include "BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

void branchSumsHelper(Node* current_node, int runningSum, vector<int>& sums) {
    

    if (current_node == nullptr)
        return;

    runningSum = runningSum + current_node -> data;

    if (current_node -> left == nullptr && current_node -> right == nullptr) {
        sums.push_back(runningSum);
        return;
    }

    branchSumsHelper(current_node -> left, runningSum, sums);
    branchSumsHelper(current_node -> right, runningSum, sums);

    return;
}

vector<int> branchSums(BinaryTree tree) {

    vector<int> sums;
    branchSumsHelper(tree.head, 0, sums);
    return sums;
}

int main(int argc, char* argv[]) {

    BinaryTree tree(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);

    vector<int> sums = branchSums(tree);

    for (auto element: sums)
        cout << element << endl;

    return 0;
}
