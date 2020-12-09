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

class BinaryTree {

    public:
         
        Node* rootNode;

        BinaryTree() {
            rootNode = new Node();
        }

        BinaryTree(int value) {
            rootNode = new Node(value);
        }

        Node* getRoot() {
            return rootNode;
        }

        void insert(int value) {

            if (rootNode == nullptr) {
                rootNode = new Node(value);
                return;
            }

            queue<Node*> levelQueue;
            levelQueue.push(rootNode);

            
            while (!levelQueue.empty()) {

                int levelsize = levelQueue.size();
                for (int i = 0; i < levelsize; i++) {

                    Node* currentNode = levelQueue.front();
                    levelQueue.pop();

                    if (currentNode -> leftChild != nullptr) 
                        levelQueue.push(currentNode -> leftChild);

                    else {
                        currentNode -> leftChild = new Node(value);
                        return;
                    }

                    if (currentNode -> rightChild != nullptr)
                        levelQueue.push(currentNode -> rightChild);

                    else {
                        currentNode -> rightChild = new Node(value);
                        return;
                    }
                }
            }
               return;
        }

        void inOrder(Node* currentNode) {

            if (currentNode == nullptr)
                return;

            inOrder(currentNode -> leftChild);
            cout << currentNode -> value << " ";
            inOrder(currentNode -> rightChild);

            return;
        }


};
