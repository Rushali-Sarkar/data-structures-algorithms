#include"BST.h"
#include<iostream>
#include<vector>

using namespace std;


vector<int> inOrder(Node* currentNode, vector<int>& inorder) {

    if (currentNode == nullptr)
        return inorder;

    inOrder(currentNode -> leftChild, inorder);
    inorder.push_back(currentNode -> value);
    inOrder(currentNode -> rightChild, inorder);

    return inorder;
}

vector<int> postOrder(Node* currentNode, vector<int>& postorder) {

    if (currentNode == nullptr)
        return postorder;

    postOrder(currentNode -> leftChild, postorder);
    postOrder(currentNode -> rightChild, postorder);
    postorder.push_back(currentNode -> value);
     
    return postorder;
}

vector<int> preOrder(Node* currentNode, vector<int>& preorder) {

    if (currentNode == nullptr)
        return preorder;

    preorder.push_back(currentNode -> value);
    preOrder(currentNode -> leftChild, preorder);
    preOrder(currentNode -> rightChild, preorder);

    return preorder;
}


int main(int argc, char* argv[]) {

    vector<int> inorder;
    vector<int> postorder;
    vector<int> preorder;

    BinarySearchTree bst(10);
    bst.insertBST(5);
    bst.insertBST(15);
    bst.insertBST(2);
    bst.insertBST(5);
    bst.insertBST(13);
    bst.insertBST(22);

    inorder = inOrder(bst.getRoot(), inorder);
    postorder = postOrder(bst.getRoot(), postorder);
    preorder = preOrder(bst.getRoot(), preorder);

    cout << "In Order Traversal: " << endl;
    for (auto element: inorder)
         cout << element << " ";
    cout << endl;

    cout << "Pre Order Traversal: " << endl;
    for (auto element: preorder)
        cout << element << " ";
    cout << endl;

    cout << "Post Order Traversal: " << endl;
    for (auto element: postorder)
        cout << element << " ";
    cout << endl;

    return 0;
}




