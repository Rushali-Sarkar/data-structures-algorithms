/* Problem Statement 
 *
 * Implement a function int findHeight(Node* rootNode), which returns the height of a given binary search tree. An illustration is
 * also provided for your understanding.
 *
 * -> Height of a Node - The number of edges between a node and its deeepes descendent
 * -> Height of a Tree - Height of its root node
 *
 *  Also, keep in mind that the height if an empty tree and leaf nodes is zero.
 *
 *  Output 
 *
 *  Returns the maximum depth or height of a binary tree
 *
 *  Sample Input
 *
 *  bst = {
 *  6 -> 4, 9
 *  4 -> 2, 5
 *  9 -> 8, 12
 *  12 -> 10, 14
 *  }
 *
 *  where parent -> leftChild, rightChild
 *
 *  Sample Output
 *
 *  3
 */
#include<iostream>
#include<queue>

using namespace std;


class Node {

    public:

        int value;
        Node* leftChild;
        Node* rightChild;

        Node() {

            value = 0;
            leftChild = nullptr;
            rightChild = nullptr;
        }

        Node(int val) {

            value = val;
            leftChild = nullptr;
            rightChild = nullptr;
        }

};

class BinarySearchTree {

    public:
        Node* rootNode;

        BinarySearchTree() {
            rootNode = new Node();
        }

        BinarySearchTree(int value) {
            rootNode = new Node(value);
        }

        Node* getRoot() {
            return rootNode;
        }

        void insertBST(int value) {

            Node* currentNode = rootNode;
            Node* parentNode;

            while (currentNode != nullptr) {

                parentNode = currentNode;

                if (value < currentNode -> value) 
                    currentNode = currentNode -> leftChild;

                else
                    currentNode = currentNode -> rightChild;

            }

            if (parentNode -> value > value)
                parentNode -> leftChild = new Node(value);

            else
                parentNode -> rightChild = new Node(value);

            return;
        }
};
            

/* int findHeight(Node* rootNode) {
    
    queue<Node*> levelOrderQueue;
    levelOrderQueue.push(rootNode);

    int height = 0;

    while (!levelOrderQueue.empty()) {

        int levelsize = levelOrderQueue.size();
        Node* currentNode;

        for (int i = 0; i < levelsize; i++) {
            currentNode = levelOrderQueue.front();
            levelOrderQueue.pop();
            if (currentNode -> leftChild != nullptr)
                levelOrderQueue.push(currentNode -> leftChild);
            if (currentNode -> rightChild != nullptr)
                levelOrderQueue.push(currentNode -> rightChild);
        }

        height++;
    }
    return height - 1;
} */


 int findHeight(Node* rootNode) {  

     if (rootNode == nullptr) 
         return -1;

     return 1 + max(
             findHeight(rootNode -> leftChild),
             findHeight(rootNode -> rightChild));
 }

int main() {

    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);
    cout << findHeight(BST.getRoot()) << endl;
}
