#include<iostream>
#include<cmath>
#include"BST.h"

using namespace std;


int closestvalueBST(BinarySearchTree bst, int value) {

    Node* rootNode = bst.getRoot();

    int element = rootNode -> value;
    int difference = abs(element - value);

    while (rootNode != nullptr) {

        int minimum_difference = abs(rootNode -> value - value);
        if (minimum_difference < difference) {
           element = rootNode -> value;
          difference = minimum_difference;
        }

        if (minimum_difference == 0)
            return rootNode -> value;

       if (value < rootNode -> value)
          rootNode = rootNode -> leftChild;

       else
          rootNode = rootNode -> rightChild;
    }

   return element;
}

int main(int argc, char* argv[]) {

    BinarySearchTree bst(10);
    bst.insertBST(5);
    bst.insertBST(15);
    bst.insertBST(2);
    bst.insertBST(5);
    bst.insertBST(13);
    bst.insertBST(22);
    bst.insertBST(1);
    bst.insertBST(14);

    cout << closestvalueBST(bst, 25) << endl;
    return 0;
}

/* The time complexity of this algorithm is O(logN) because we are eliminating half of the tree each time we traverse below.
 * But in worst case where there is no branching at all the time complexity would be O(n)
 * The space complexity is O(1) because we are not using any significant amount of extra space but just constant space no matter
 * what the input is.*/

