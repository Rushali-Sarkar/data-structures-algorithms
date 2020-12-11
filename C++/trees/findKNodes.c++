/* Problem Statement
 *
 * Implement  a function string findKNodes(Node* root, int k), which finds and returns nodes at k distance from the root in the
 * given binary tree.
 *
 * Output
 *
 * Returns all the nodes in a stringed list format which are at a distance k from the root node.
 *
 * Sample Input
 *
 * bst = {
 *  6 -> 4, 9
 *  9 -> 8, 12
 *  12 -> 10, 14
 *  }
 *
 *  where parent -> leftChild, rightChild
 *  k= 2
 *
 *  Sample Output
 *
 *  2, 5, 8, 12
 */

#include<iostream>
#include<queue>
#include<string>

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

        Node* insert (Node* currentNode, int value) {

            if (currentNode == nullptr) 
                return new Node(value);

            else if (currentNode -> value > value)
                currentNode -> leftChild =  insert (currentNode -> leftChild, value);

            else
                currentNode -> rightChild =  insert (currentNode -> rightChild, value);

            return currentNode;
        }

        void insertBST(int value) {

            if (getRoot() == nullptr) {
                rootNode = new Node(value);
                return;
            }

            insert (rootNode, value);
            return;
        }
};


// Helper recuresive function to traverse tree  and append all the nodes
// at k distance into result string


void findK(Node* root, int k, string* result) {

    if (root == nullptr)
        return;

    queue<Node*> levelOrderTraversal;
    levelOrderTraversal.push(root);
    int distanceFromRoot = 0;
        
    while (!levelOrderTraversal.empty() && distanceFromRoot <= k) {

       int  levelSize = levelOrderTraversal.size();
        
         

        for (int i = 0; i < levelSize; i++) {

            Node* currentNode = levelOrderTraversal.front();
            levelOrderTraversal.pop();

            

            if (currentNode -> leftChild != nullptr)
                levelOrderTraversal.push(currentNode -> leftChild);

            if (currentNode -> rightChild != nullptr)
                levelOrderTraversal.push(currentNode -> rightChild);

            if (distanceFromRoot == k)
               *result = *result  + to_string(currentNode -> value) + " , " ;
        }

        distanceFromRoot++;
    }

    return;
}



string findKNodes(Node* root, int k) {

    string* result = new string();
    findK(root, k, result);
    return *result;
}


int main() {

    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);

    cout << findKNodes(BST.getRoot(), 2) << endl;
}//Your code here




                    
