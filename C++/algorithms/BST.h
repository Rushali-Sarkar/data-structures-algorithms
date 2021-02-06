#include<iostream>
#include<vector>
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
        vector<int> inOrder;
        vector<int> postOrder;
        vector<int> preOrder;
        vector<vector<int>> levelOrder;
        vector<int> depthOrder;

        BinarySearchTree() {
            rootNode = nullptr;
        }

        BinarySearchTree(int value) {
            rootNode = new Node(value);
        }

        Node* getRoot() {
            return rootNode;
        }

        void insertBST(int value) {

            if (getRoot() == nullptr) {
                rootNode = new Node(value);
                return;
            }

            Node* currentNode = rootNode;
            Node* parentNode;

            while (currentNode != nullptr) {

                parentNode = currentNode;

                if (value < currentNode -> value)
                   currentNode = currentNode -> leftChild;

                else
                   currentNode = currentNode -> rightChild;
            }

           if (value < parentNode -> value)
              parentNode -> leftChild = new Node(value);

           else
              parentNode -> rightChild = new Node(value);

          return;
        } 

        void inOrderTraversal(Node* current) {

            if (current == nullptr)
                return;
            
            else {
                   
                inOrderTraversal(current -> leftChild);
                inOrder.push_back(current -> value);
                inOrderTraversal(current -> rightChild);
            }

            return;
        }

        void showInOrder() {

            inOrderTraversal(rootNode);
            for (int i = 0; i < inOrder.size(); i++)
                cout << inOrder[i] << "\t";
            cout << endl;
            return;
        }


        void postOrderTraversal(Node* current) {

            if (current == nullptr)
                return;

            else {
                postOrderTraversal(current -> leftChild);
                postOrderTraversal(current -> rightChild);
                postOrder.push_back(current -> value);
            }
            return;
        }

        void showPostOrder() {

            postOrderTraversal(rootNode);
            for (int i = 0; i < postOrder.size(); i++) 
                cout << postOrder[i] << '\t';
            cout << endl;
            return;
        }

        void preOrderTraversal(Node* current) {

            if (current == nullptr)
                return;

            else {
                preOrder.push_back(current -> value);
                preOrderTraversal(current -> leftChild);
                preOrderTraversal(current -> rightChild);
            }
            return;
        }

        void showPreOrder() {

            preOrderTraversal(rootNode);
            for (int i = 0; i < preOrder.size(); i++) 
                cout << preOrder[i] << '\t';
            cout << endl;
            return;
        }
         
        void levelOrderTraversal() {

            queue<Node*> levelOrderQueue;
            levelOrderQueue.push(rootNode);
            
            while (!levelOrderQueue.empty()) {

                int levelSize = levelOrderQueue.size();
                vector<int> currentLevel;
                    
                for (int i = 0; i < levelSize; i++) {

                   Node* currentNode = levelOrderQueue.front();
                   levelOrderQueue.pop();
                    currentLevel.push_back(currentNode -> value);
                        
                   

                   if (currentNode -> leftChild != nullptr)
                       levelOrderQueue.push(currentNode -> leftChild);

                   if (currentNode -> rightChild != nullptr)
                       levelOrderQueue.push(currentNode -> rightChild);
                }

                levelOrder.push_back(currentLevel);
            }
            return;
        }

        void showLevelOrder() {

            levelOrderTraversal();
            for (int i = 0 ; i < levelOrder.size(); i++) {
                for (int j = 0; j < levelOrder[i].size(); j++) 
                    cout << levelOrder[i][j] << '\t';
                cout << endl;
            }
            
            return;
        }

};
